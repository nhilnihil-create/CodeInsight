#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  int r=n,l=0;
  
  string t,u;
  cout << l << endl;
  cin >> t;
  if(t=="Vacant"){return 0;}
  u=t;
  
  while(r-l>1){
    int y=(l+r)/2;
    cout << y << endl;
    string s;
    cin >> s;
    if(s=="Vacant"){return 0;}
    if(((y-l+1)%2==0 && u!=s) || ((y-l+1)%2 != 0 && u==s)){
      l=y;
      u=s;
    }else {r=y;}
}
  
}