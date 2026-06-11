#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
  int N;
  cin>>N;
  vector<string> s(N);
  for(int i = 0; i < N; i++) cin>>s[i];
  int ans = 0;
  for(int i = 0; i < N; i++){
    bool can = true;
    for(int j = 0; j < N; j++){
      for(int k = 0; k < N; k++){
        if(s[j][k]!=s[(k+N-i)%N][(j+i)%N]){
          can=false;
          break;
        }
      }
      if(!can) break;
    }
    if(can) ans++;
  }
  cout<<ans*N<<endl;
}