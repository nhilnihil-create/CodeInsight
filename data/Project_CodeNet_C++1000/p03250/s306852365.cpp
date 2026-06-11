#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b,c;
  cin >> a >> b >> c;
  cout << max(a*10+b+c,max(b*10+a+c,c*10+a+b));
}
/*
  for(int i=0;i<4;i++){
    if(s[i]=='-')o----;
    o++;
  }
  cout << o;
}
*/
