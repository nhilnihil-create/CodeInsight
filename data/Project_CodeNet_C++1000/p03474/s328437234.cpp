#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int64_t MOD=1000000007;

int main() {
  int A,B; cin>>A>>B;
  string S; cin>>S;
  bool ans=true;
  rep(i,A+B+1){
    if(i==A&&S.at(i)!='-') ans=false;
    if(i!=A&&S.at(i)=='-') ans=false;
  }
  if(ans) cout<<"Yes";
  else cout<<"No";
}
