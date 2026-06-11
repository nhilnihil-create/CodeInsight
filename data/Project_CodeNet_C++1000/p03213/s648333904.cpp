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
  map<int,int> m;
  int ans = 0;
  for(int i = 1; i <= N; i++) {
    int t = i;
    for(int j = 2; j<=t; j++) {
      while(t%j==0){
        m[j]++;
        if(m[j]==2){
          int k = 0;
          for(auto x:m){
            if(x.first==j)continue;
            if(x.second>=24)ans++;
            if(x.second>=4)k++;
          }
          ans += (k*(k-1))/2;
        }
        if(m[j]==4) {
          int k=0,s=0;
          for(auto x:m){
            if(x.first==j)continue;
            if(x.second>=14)ans++;
            if(x.second>=4) k++;
            if(x.second>=2)s++;
          }
          ans += k*(s-1);
        }
        if(m[j]==14){
          for(auto x:m){
            if(x.first==j)continue;
            if(x.second>=4)ans++;
          }
        }
        if(m[j]==24){
          for(auto x:m){
            if(x.first==j)continue;
            if(x.second>=2)ans++;
          }
        }
        if(m[j]==74)ans++;
        t/=j;
      }
    }
  }
  cout<<ans <<endl;
}
    
    