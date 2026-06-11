#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N;
  cin>>N;
  vector<int> v(N);
  for(int i = 0; i < N; i++) cin>>v[i];
  vector<int> ans;
  for(int i = 0; i < N; i++) {
    for(int j = (int)v.size()-1;j>=0;j--){
      if(v[j]==j+1){
        ans.push_back(j+1);
        v.erase(v.begin()+j);
        break;
      }
    }
  }
  if((int)v.size()!=0)cout<<-1<<endl;
  else{
    reverse(ans.begin(),ans.end());
    for(auto x:ans) cout<<x<<endl;
  }
}