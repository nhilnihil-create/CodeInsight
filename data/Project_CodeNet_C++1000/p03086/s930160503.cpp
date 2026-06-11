#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
#define ll long long
#define rep(i,n) for (int i = 0; i < (n); i++)

int main() {
  string S;
  cin >> S;
  int ans=0;
  int cnt=0;
  rep(i,S.size()){
    cnt=0;
      for(int j=i;j<S.size();j++){
      if(S[j] =='A' || S[j] =='C' || S[j] =='G' || S[j] =='T'){
        cnt++;

      }else break;
    }
    chmax(ans,cnt);
    
  }
  cout << ans << endl;
}
