#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  ll N;
  cin>>N;
  vector<int> ans;
  ll t = N;
  while(t!=0LL){
    if(t%2LL==0LL)ans.push_back(0);
    if(t%2LL!=0LL){
      ans.push_back(1);
      t--;
    }
    t/=(-2LL);
  }
  if((int)ans.size()==0) ans.push_back(0);
  reverse(ans.begin(),ans.end());
  for(auto x:ans) cout<<x;
  cout<<endl;
}