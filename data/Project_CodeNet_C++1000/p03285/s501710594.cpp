#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  scanf("%d",&n);
  int a=n/4+1,b=0;
  //aは4$,bは7$
  while((a*4+b*7!=n)&&a>0){
    a--;
    b=0;
    while(a*4+b*7<n)
      b++;
  }
  if(a*4+b*7==n)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}