#include<bits/stdc++.h>
using namespace std;
int main(){
  char s[200000];
  cin >> s;
  int c=0;
  int n=strlen(s);
  for(int i=0;i<n;i++){
    if(s[i]=='0')c++;
  }
  cout << 2*min(c,n-c);
}
