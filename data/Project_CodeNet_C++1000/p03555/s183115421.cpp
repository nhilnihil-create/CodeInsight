#include <bits/stdc++.h>

using namespace std;

int main() {
  string s,t;
  cin>>s>>t;
  string ss=s;
  string tt=t;
  reverse(ss.begin(), ss.end()); reverse(tt.begin(),tt.end());
	cout<<((tt==s && ss==t)? "YES\n" : "NO\n");
}