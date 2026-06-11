#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<complex>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
#include<tuple>
using namespace std;
typedef long long ll;
typedef unsigned int ui;
const ll mod = 1000000007;
const ll INF = (ll)1000000007 * 1000000007;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define Per(i,sta,n) for(int i=n-1;i>=sta;i--)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef long double ld;
typedef complex<ld> Point;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;

int n,m,c[200010][2];
string s;
vector<int> G[200010];
queue<int> que;
bool erased[200010];

void solve(){
  cin >> n >> m;
  cin >> s;
  rep(i,m){
    int a,b;
    cin >> a >> b;
    a--;b--;
    G[a].push_back(b);
    if (s[b]=='A') c[a][0]+=1;
    else c[a][1]+=1;
    G[b].push_back(a);
    if (s[a]=='A') c[b][0]+=1;
    else c[b][1]+=1;
  }
  rep(i,n){
    if (c[i][0]==0 || c[i][1]==0) {
      que.push(i);
      erased[i]=true;
    }
  }
  while(!que.empty()){
    int t=que.front();que.pop();
    int co;
    if (s[t]=='A') co=0;
    else co=1;
    for(int l:G[t]){
      c[l][co]-=1;
      if (c[l][co]==0 && !erased[l]) {
        que.push(l);
        erased[l]=true;
      }
    }
  }
  rep(i,n){
    if (!erased[i]) {
      cout << "Yes" << endl;
      return;
    }
  }
  cout << "No" << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(50);
    solve();
}