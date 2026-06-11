#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int INF = 1<<30;
const ll mod = 1000000007LL;

bool pri(int x){ //素数判定
  bool ok = true;
  for(int i = 2; i*i<=x;i++){
    if(x%i==0) {
      ok = false;
      break;
    }
  }
  if(x==1)ok = false;
  return ok;
}

int main() {
  int N;
  cin>>N;
  vector<int> ans(N);
  ans[0]=11;
  for(int i = 1; i < N; i++){
    ans[i]=ans[i-1]+10;
    while(!pri(ans[i])){
      ans[i]+=10;
    }
  }
  for(auto x:ans) cout<<x<<" ";
  cout<<endl;
}