#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
  int N,C;
  cin>>N>>C;
  vector<vector<int>> time(C,vector<int>(200100));
  for(int i = 0; i < N; i++){
    int s,t,c;
    cin>>s>>t>>c;
    time[c-1][2*s]++;
    time[c-1][2*t]--;
  }
  for(int i = 0; i < C;i++){
    for(int j = 1; j < 200100;j++){
      if(time[i][j]==1){
        time[i][j-1]=1;
        time[i][j]=0;
      }
    }
  }
  vector<int> all(200100,0);
  for(int i = 0; i < 200100; i++){
    for(int j = 0; j < C; j++){
      all[i]+=time[j][i];
    }
  }
  int ans = 0;
  for(int i = 1; i < 200100; i++){
    all[i]+=all[i-1];
    chmax(ans,all[i]);
  }
  cout<<ans<<endl;
}