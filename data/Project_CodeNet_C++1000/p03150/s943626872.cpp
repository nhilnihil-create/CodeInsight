#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  string s;
  cin>>s;
  bool ans=0;
  int n=s.size()-1;
  if(s[0]=='k'&&s[1]=='e'&&s[2]=='y'&&s[3]=='e'&&s[4]=='n'&&s[5]=='c'&&s[0]=='e')ans=1;
  if(s[0]=='k'&&s[n-5]=='e'&&s[n-4]=='y'&&s[n-3]=='e'&&s[n-2]=='n'&&s[n-1]=='c'&&s[n]=='e')ans=1;
  if(s[0]=='k'&&s[1]=='e'&&s[n-4]=='y'&&s[n-3]=='e'&&s[n-2]=='n'&&s[n-1]=='c'&&s[n]=='e')ans=1;
  if(s[0]=='k'&&s[1]=='e'&&s[2]=='y'&&s[n-3]=='e'&&s[n-2]=='n'&&s[n-1]=='c'&&s[n]=='e')ans=1;
  if(s[0]=='k'&&s[1]=='e'&&s[2]=='y'&&s[3]=='e'&&s[n-2]=='n'&&s[n-1]=='c'&&s[n]=='e')ans=1;
  if(s[0]=='k'&&s[1]=='e'&&s[2]=='y'&&s[3]=='e'&&s[4]=='n'&&s[n-1]=='c'&&s[n]=='e')ans=1;
  if(s[0]=='k'&&s[1]=='e'&&s[2]=='y'&&s[3]=='e'&&s[4]=='n'&&s[5]=='c'&&s[n]=='e')ans=1;
  if(s[n-6]=='k'&&s[n-5]=='e'&&s[n-4]=='y'&&s[n-3]=='e'&&s[n-2]=='n'&&s[n-1]=='c'&&s[n]=='e')ans=1;
  if(ans)cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
}

