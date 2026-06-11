#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int64_t MOD=1000000007;
const long long INF = 1LL<<60;

int main() {
  int64_t ans=0,temp=0;
  string S; cin>>S;
  rep(i,S.size()-1){
    if(S.at(i)=='A') temp++;
    else if(S.at(i)=='B'&&S.at(i+1)=='C'){
      ans+=temp;
      S.at(i+1)='A';
      i++;
    }
    else temp=0;
  }
  cout<<ans;      
}
