#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int INF = 1<<30;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N;
  cin >> N;
  string s;
  cin>>s;
  vector<int> v(N);
  for(int i = 0; i < N; i++){
    if(i==0){
      if(s[i]=='.') v[i]=1;
      if(s[i]=='#') v[i]=0;
    }
    else{
      if(s[i]=='.') v[i]=v[i-1]+1;
      if(s[i]=='#') v[i]=v[i-1];
    }
  }
  int ans = INF;
  for(int i = 0; i <= N;i++){
    if(i==0)chmin(ans,v[N-1]);
    else chmin(ans,i-v[i-1]+v[N-1]-v[i-1]);
  }
  cout<<ans<<endl;
}