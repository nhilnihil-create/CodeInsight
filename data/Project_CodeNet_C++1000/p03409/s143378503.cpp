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
#include<cassert>
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
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

int n;
int x[110][2],y[110][2];

void solve(){
  cin >> n;
  vector<P> v;
  rep(i,n){
    v.push_back(P(i,0));
    v.push_back(P(i,1));
  }
  rep(i,n){
    cin >> x[i][0] >> y[i][0];
  }
  rep(i,n){
    cin >> x[i][1] >> y[i][1];
  }
  sort(v.begin(),v.end(),[](P a,P b){
    return x[a.first][a.second]<x[b.first][b.second];
  });
  set<int> se={};
  int ans=0;
  rep(i,2*n){
    int s=v[i].first,t=v[i].second;
    if(t==0){
      se.insert(y[s][t]);
    }
    else{
      auto it=se.lower_bound(y[s][t]);
      if(it==se.begin()) continue;
      it--;
      ans+=1;
      se.erase(it);
    }
  }
  cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(50);
    solve();
}