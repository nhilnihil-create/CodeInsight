#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
#include<cassert>
#include<numeric>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
using namespace std;
const int INF = 1001001001;
const long long LINF = 1001002003004005006ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
typedef long long ll;
typedef pair<int,int> P;

int main(){
  int n,k;
  cin >> n >> k;
  int t[n],d[n];
  rep(i,n)cin >> t[i] >> d[i];
  vector<P> v;
  rep(i,n){
    v.push_back(make_pair(t[i],d[i]));
  }
  sort(v.begin(),v.end(),[](P a,P b) { return a.second > b.second; });
  map<int,int> mp;
  ll sum = 0;
  rep(i,k){
    chmax(mp[v[i].first],v[i].second);
    sum += v[i].second;
  }
  priority_queue<int,vector<int>,greater<int>> nmx;
  vector<int> mx(n+1);
  rep(i,k){
    if(mp[v[i].first]==v[i].second&&mx[v[i].first]==0)mx[v[i].first]=1;
    else nmx.push(v[i].second);
  }
  priority_queue<int> left;
  map<int,int> mp_left;
  for(int i=k;i<n;i++){
    if(!mp.count(v[i].first))chmax(mp_left[v[i].first],v[i].second);
  }
  for(auto p:mp_left){
    left.push(p.second);
  }
  ll sz = mp.size();
  ll ans = sum+sz*sz;
  int m = left.size();
  rep(i,m){
    sz++;
    if(sz>k)break;
    sum-=nmx.top();nmx.pop();
    sum+=left.top();left.pop();
    chmax(ans,sum+sz*sz);
  }
  cout << ans << endl;
}