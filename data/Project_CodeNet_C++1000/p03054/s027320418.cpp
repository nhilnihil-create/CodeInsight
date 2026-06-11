#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int H,W,N;
  cin>>H>>W>>N;
  vector<int> place(2);
  cin>>place[0]>>place[1];
  string S,T;
  cin>>S>>T;
  reverse(S.begin(),S.end());
  reverse(T.begin(),T.end());
  int u=1,l=1, d=H, r=W;
  bool can = true;
  for(int i = 0; i < N; i++) {
    if(T[i]=='L') r=min(r+1,W);
    if(T[i]=='R') l=max(l-1,1);
    if(T[i]=='U') d=min(d+1,H);
    if(T[i]=='D') u=max(1,u-1);
    if(S[i]=='R') r--;
    if(S[i]=='L') l++;
    if(S[i]=='U') u++;
    if(S[i]=='D') d--;
    if(l>r||u>d) {
      can=false;
      break;
    }
  }
  if(can&&u<=place[0]&&d>=place[0]&&l<=place[1]&&r>=place[1]) cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
}