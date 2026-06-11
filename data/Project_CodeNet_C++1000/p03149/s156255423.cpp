#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a;
  bool n1=false;
  bool n2=false;
  bool n3=false;
  bool n4=false;
  for(int i=0;i<4;i++){
    cin>>a;
    if(a==1)n1=true;
    else if(a==9)n2=true;
    else if(a==7)n3=true;
    else if(a==4)n4=true;
  }
  if(n1==true&&n2==true&&n3==true&&n4==true)
    cout<<"YES";
  else cout << "NO";
    
}