#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>> n;
  int n1 = n%10;
  n/=10;
  int n2 = n%10;
  n/=10;
  int n3 = n%10;
  n/=10;
  int n4 = n%10;
  if(n1==n2&&n2==n3||n2==n3&&n3==n4){
    cout<<"Yes"<<endl;
  }
  else{
    cout<<"No"<<endl;
  }



}
