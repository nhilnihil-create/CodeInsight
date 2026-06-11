#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  int n;
  cin>>n;
  unordered_map<int,int> ma,mb;
  rep(i,n){
    int t;
    cin >> t;
    if(i%2==0) ma[t]++;
    if(i%2==1) mb[t]++;
  }
  vector<pair<int,int>> va,vb;
  for(auto x:ma){
    va.push_back(make_pair(x.second,x.first));
  }
  for(auto x:mb){
    vb.push_back(make_pair(x.second,x.first));
  }
  sort(va.begin(),va.end());
  reverse(va.begin(),va.end());
  sort(vb.begin(),vb.end());
  reverse(vb.begin(),vb.end());
  va.push_back(make_pair(0,-1));
  vb.push_back(make_pair(0,-1));
  int ans = 0;
  if(va[0].second!=vb[0].second)ans = n-va[0].first-vb[0].first;
  else {
    int t = max(va[0].first+vb[1].first,va[1].first+vb[0].first);
    ans = n - t;
  }
  cout<<ans<<endl;
}
