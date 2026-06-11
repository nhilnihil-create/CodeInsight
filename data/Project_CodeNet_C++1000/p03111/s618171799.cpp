#include<bits/stdc++.h>
#include<iomanip>
using namespace std;
typedef long long ll;
typedef long  l;
typedef pair<int,int> P;
#define rep(i,n) for(int i=0;i<n;i++)
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
const double PI=3.141592653589;
const int INF=1000000007;
const ll LMAX=1000000000000001;
int gcd(int a,int b){if(a<b)swap(a,b);int c=a%b;while(c!=0){a=b;b=c;c=a%b;}return b;}
ll lcm(ll a,ll b){return a*b/gcd(a,b);}
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

int a, b, c, n;
vector<int> L(10);
int ans = INF;

void dfs(int id, int alen, int blen, int clen, int cos){
  // cout << "a" << endl;
  if(id == n){
    if(!(alen == 0 || blen == 0 || clen == 0))
    ans = min(ans, cos + abs(a - alen) + abs(b - blen) + abs(c - clen));
  }else{
    dfs(id + 1, alen, blen, clen, cos);
    if(alen == 0)
    dfs(id + 1, alen + L[id], blen, clen, cos);
    else
    dfs(id + 1, alen + L[id], blen, clen, cos + 10);
    if(blen == 0)
    dfs(id + 1, alen, blen + L[id], clen, cos);
    else
    dfs(id + 1, alen, blen + L[id], clen, cos + 10);
    if(clen == 0)
    dfs(id + 1, alen, blen, clen + L[id], cos);
    else
    dfs(id + 1, alen, blen, clen + L[id], cos + 10);
  }
}

int main(){
  cin >> n >> a >> b >> c;
  rep(i, n) cin >> L[i];

  dfs(0, 0, 0, 0, 0);
  cout << ans << endl;

  return 0;
}
