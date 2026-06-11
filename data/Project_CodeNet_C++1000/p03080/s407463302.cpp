#include<iostream>
using namespace std;

int main() {
  int n;
  char s[101];
  int r=0,b=0;
  cin >> n >> s;
  for(int i=0;i<n;i++){
    if(s[i]=='R') r++;
    if(s[i]=='B') b++;
  }
  if(r>b) cout << "Yes";
  else cout << "No";
  return 0;
}