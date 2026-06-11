#include <bits/stdc++.h>
#define ull unsigned long long
#define mem 26
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  string s;
  cin>>s;
  int n = s.length();
  int j = n-1;
  ull moves=0;
  for(int i=n-1;i>=0;i--) {
    if(s[i]=='B') {
      moves+=(j-i);
      j--;
    }
  }
  cout<<moves;
  cout<<"\n";
  return 0;
}