#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b,c,k;
  cin >> a>>b>> c>>k;
  int i,sum=0,p=max(a,max(b,c));
  for(i=0;i<k;i++){
    p=p*2;
  }
  sum=p+a+b+c-max(a,max(b,c));
  cout << sum;
                  }
