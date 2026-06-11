#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define repp(i,m,n) for(int (i)=(m);(i)<(n);(i)++)
#define repm(i,n) for(int (i)=(n-1);(i)>=0;(i)--)
#define INF (1ll<<60)
#define all(x) (x).begin(),(x).end()
typedef long long lint;
const lint MOD =1000000007;
const lint MAX = 10000000;
using Graph =vector<vector<lint>>;
typedef pair<lint,lint> P;
 
 
lint fac[MAX], finv[MAX], inv[MAX];
 
void COMinit() 
{
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (lint i = 2; i < MAX; i++)
    {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}
 
long long COM(lint n, lint k)
{
    if (n < k)
        return 0;
    if (n < 0 || k < 0)
        return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
 
lint primary(lint num)
{
    if (num < 2) return 0;
    else if (num == 2) return 1;
    else if (num % 2 == 0) return 0;
 
    double sqrtNum = sqrt(num);
    for (int i = 3; i <= sqrtNum; i += 2)
    {
        if (num % i == 0)
        {
            return 0;
        }
    }
 
    return 1;
}
   long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}
    lint lcm(lint a,lint b){
        return a/__gcd(a,b)*b;
    }
     lint gcd(lint a,lint b){
        return __gcd(a,b);
    }    

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
lint f[100005];
  int main(){
        lint N,C;
        cin>>N>>C;
        vector<vector<P>> x(30);
        rep(i,N){
            lint s,t,c;
            cin>>s>>t>>c;
            --c;
            x[c].push_back(make_pair(s,t));
        }
        vector<P> g;
        rep(i,30){
            lint s,v,s1,v1;
            sort(all(x[i]));
            rep(j,x[i].size()){
               if(j==0){
                    tie(s,v)=x[i][j];
               }else{
                   tie(s1,v1)=x[i][j];
                   if(s1==v)v=v1;
                   else {
                       g.push_back(make_pair(s,v));
                       s=s1;
                       v=v1;
                   }

               }
            }
           if(x[i].size()>0) g.push_back(make_pair(s,v));
        }
        rep(i,g.size()){
            f[g[i].first]++;
            f[g[i].second+1]--;
           // cout<<g[i].first<<" "<<g[i].second<<endl;
        }
        rep(i,100004){
            f[i+1]+=f[i];
        }
    cout<<*max_element(f,f+100005);
  }
  
  
     
  