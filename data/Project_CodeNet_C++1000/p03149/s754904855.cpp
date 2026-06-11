#include <bits/stdc++.h>
using namespace std;

 int main(){

  int n = 4;

  int a[4];

  for(int i=0;i<n;i++){
    cin>>a[i];
  }

  sort(a,a+n);

  if(a[0] == 1 && a[1] == 4 && a[2] == 7 && a[3] == 9)
    cout<<"YES"<<endl;
  else
    cout<<"NO"<<endl;



 return 0;
 }
