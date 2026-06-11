#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(v) v.begin(),v.end()
using namespace std;
typedef long long ll;
 
int main(){
  string S;
  cin>>S;
  vector<char> a(S.length());
  vector<char> b(S.length());
  int ans1=0;
  int ans2=0;
  for(int i=0;i<S.length();i+=2) a[i]='0';
  for(int i=1;i<S.length();i+=2) a[i]='1';
  for(int i=0;i<S.length();i+=2) b[i]='1';
  for(int i=1;i<S.length();i+=2) b[i]='0';
  rep(i,S.length()) if(S[i]!=a[i]) ans1++;
  rep(i,S.length()) if(S[i]!=b[i]) ans2++;
  ans1=min(ans1,ans2);
  cout<<ans1<<endl;
}   