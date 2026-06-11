#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  long long k; cin>>s>>k;
  char a=s[0];
  for(int i=0;a=='1'&&i<k;i++) a=s[i];
  cout<<a;
}