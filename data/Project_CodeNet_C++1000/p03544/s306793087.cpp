#include <bits/stdc++.h>
using namespace std;

int main(){
  long long int n;
  cin>>n;
  long long int a=2;
  long long int b=1;
  long long int c=0;
  for(int i=0;i<n-1;i++){
      c=a+b;
      a=b;
      b=c;
    }
    if(n==1) cout<<"1"<<endl;
    else cout<<c<<endl;
}