#include<bits/stdc++.h>
using namespace std;
int main(){
  char s[200];
  cin >> s;
  int e=0,z;
  if(s[0]=='A'){
    for(int i=2;i<strlen(s)-1;i++){
      if(s[i]=='C'){
        e++;
        z=i;
      }
    }
    for(int i=1;i<strlen(s);i++){
      if(e==1&&z==i)continue;
      else if(s[i]>='A'&&s[i]<='Z')e=2;
    }
    if(e==1)cout << "AC";
    else cout << "WA";
  }
  else cout << "WA";
}
