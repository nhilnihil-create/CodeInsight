#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
  int N,K;
  string S;
  cin >> N >> K >> S;
  vector<int> v;
  int cnt = 0;
  for(int i = 0; i < N; i++) {
    if(S[i]=='1')cnt++;
    if(S[i]=='0')cnt--;
    if(i==N-1)v.push_back(cnt);
    else if(S[i]!=S[i+1]){
        v.push_back(cnt);
        cnt=0;
    }
  }
  int ans = 0;
  if(S[0]=='1'){
    int k = 0;
    for(int i = 0; i <= min(2*K,(int)v.size()-1); i++) {
      k+=abs(v[i]);
    }
    chmax(ans,k);
    for(int i = 0; 2*i+2*K+1<(int)v.size();i++){
      if(2*i+2*K+2<(int)v.size()){
        k-=v.at(2*i)-v.at(2*i+1);
        k+=(-v.at(2*K+2*i+1))+v.at(2*K+2*i+2);
        chmax(ans,k);
      }
      else if(2*i+2*K+2==(int)v.size()){
        k-=v.at(2*i)-v.at(2*i+1);
        k+=(-v.at(2*K+2*i+1));
        chmax(ans,k);
      }
    }
  }
  else {
    int k = 0;
    for(int i = 0; i < min(2*K,(int)v.size()); i++) {
      k+=abs(v.at(i));
    }
    chmax(ans,k);
    v.erase(v.begin());
    k=0;
    for(int i = 0; i <= min(2*K,(int)v.size()-1); i++) {
      k+=abs(v.at(i));
    }
    chmax(ans,k);
    for(int i = 0; 2*i+2*K+2<(int)v.size();i++){
      k-=v.at(2*i)-v.at(2*i+1);
      k+=(-v.at(2*K+2*i+1))+v.at(2*K+2*i+2);
      chmax(ans,k);
    }
  }
  cout<<ans<<endl;
}
