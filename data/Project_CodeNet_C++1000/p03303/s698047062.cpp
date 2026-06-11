#include<bits/stdc++.h>
using namespace std;
int main(){
  char s[2000];
  cin >> s;
  int x;
  cin >> x;
  for(int i=0;i<strlen(s);i++){
    if(i%x==0)cout << s[i];
  }
}