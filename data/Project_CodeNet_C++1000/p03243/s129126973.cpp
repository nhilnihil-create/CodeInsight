#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  int a=n%10;
  int b=((n-a)%100)/10;
  int c=(n-a-b)/100;
  while(a!=b||b!=c){
    n++;
    a=n%10;
    b=((n-a)%100)/10;
    c=(n-a-b)/100;
  }
  cout<<n<<endl;
}