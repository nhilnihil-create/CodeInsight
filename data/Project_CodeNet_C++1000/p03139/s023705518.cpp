#include<iostream>
using namespace std;
int main(){
  int n,a,b;
  cin >> n >> a >> b;
  if(a>b){cout<<b<<" ";} else {cout<<a<<" ";}
  if(a+b>n){cout<<a+b-n<<endl;} else {cout<<0<<endl;}
  return 0;
}
