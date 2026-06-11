#include <bits/stdc++.h>  // ver2.2.0
#define int long long
#define endl "\n"
#define ALL(v) (v).begin(),(v).end()
#define Vi vector<int>
#define VVi vector<Vi>
#define Vs vector<string>
#define Pii pair<int,int>
#define VPii vector<Pii>
#define Tiii tuple<int,int,int>
#define PQi priority_queue<int>
#define PQir priority_queue<int,vector<int>,greater<int>>
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define FI first
#define SE second
#define cYES cout<<"YES"<<endl
#define cNO cout<<"NO"<<endl
#define cYes cout<<"Yes"<<endl
#define cNo cout<<"No"<<endl
#define sortr(v) sort(v,greater<>())
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repeq(i,a,b) for(int i=a;i<=b;i++)
#define repreq(i,a,b) for(int i=a;i>=b;i--)
#define leng(n) (int)(log10(n)+1)
#define dem(a,b) ((a+b-1)/(b))
#define Vin(a) rep(iI,0,a.size())cin>>a[iI]
#define Vout(a) rep(lZ,0,a.size()-1)cout<<a[lZ]<<' ';cout<<a.back()<<endl
#define VVout(a) rep(lY,0,a.size()){Vout(a[lY]);}
#define VPout(a) rep(lX,0,a.size())cout<<a[lX].FI<<' '<<a[lX].SE<<endl
#define INF 3000000000000000000  //  3.0 * 10 ^ 18 (MAXの1/3くらい)
#define MOD 1000000007  //  10^9 + 7
using namespace std;
 
int gcd(int a,int b){return b?gcd(b,a%b):a;}  //  最大公約数gcd
int lcm(int a,int b){return a/gcd(a,b)*b;}  //  最小公倍数lcm
void uniq(Vi &v){sort(ALL(v)); v.erase(unique(ALL(v)),v.end());}  //  uniqのやつ
 
int mypow(int x, int n, int m){  //  累乗x^n(mod m)  O(log(n))
if(n==0)return 1;if(n%2==0)return mypow(x*x%m,n/2,m);else return x*mypow(x,n-1,m)%m;}

struct UnionFind {
    vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2

    UnionFind(int N) : par(N) { //最初は全てが根であるとして初期化
        for(int i = 0; i < N; i++) par[i] = i;
    }

    int root(int x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y) { // xとyの木を併合
        int rx = root(x); //xの根をrx
        int ry = root(y); //yの根をry
        if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま
        par[rx] = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
    }

    bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};

signed main() {
  cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(12);
  int n;
  cin >> n;
  VVi gr(n,Vi(n));
  UnionFind tree(n);
  int qw,er;
  
  rep(i,0,n-1){
    cin >> qw>> er;
    qw--,er--;
    gr[qw][er]=1;
    gr[er][qw]=1;
    tree.unite(qw,er);
  }
  
  Vi a(n);
  int ans = 0;
  rep(i,0,n){
    cin >> qw;
    ans += qw;
    a[i]=qw;
  }
  sortr(ALL(a));
  ans -= a[0];
  int rt= tree.root(0);
  
  Vi ansv(n);
  int now,ct=0;
  queue<int> next,next2;
  set<int> kind;
  next.push(rt);
  kind.insert(rt);
  
  while(next.size()!=0){
    now = next.front();
    next.pop();
    ansv[now]=a[ct];
    rep(i,0,n){
      if(gr[now][i]==1 && kind.count(i)==0) {
        next.push(i);
        kind.insert(i);
      }
    }
    ct++;
  }
  cout << ans << endl;
  Vout(ansv);
  return 0;
}