#include <bits/stdc++.h>
#define ull unsigned long long
#define mem 26
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  string s;
  cin>>s;
  int c=0;
  char t[2] = {'1','0'};
  for(int i=0;s[i];i++) {
    if(s[i]!=t[i&1])
      c++;
  }
  int mc = c;
  t[0] = '0';t[1] = '1';
  c = 0;
  for(int i=0;s[i];i++) {
    if(s[i]!=t[i&1])
      c++;
  }
  mc = min(mc,c);
  cout<<mc;
  cout<<"\n";
  return 0;
}