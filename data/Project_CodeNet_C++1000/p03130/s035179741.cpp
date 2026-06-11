#include <bits/stdc++.h>
#include <math.h>
using namespace std;
int main() {
  int a[6],c1=0,c2=0,c3=0,c4=0;
  for(int i=0;i<6;i++){
    cin>>a[i];
    if(a[i]==1) c1++;
    else if(a[i]==2) c2++;
    else if(a[i]==3) c3++;
    else c4++;
  }
  if((c1>2||c2>2)||(c3>2||c4>2)) cout<<"NO"<<endl;
  else cout<<"YES"<<endl;
  
}
