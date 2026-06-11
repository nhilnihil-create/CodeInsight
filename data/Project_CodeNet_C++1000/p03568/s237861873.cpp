#include<iostream>
using namespace std;
int pow(int x,int y){
  int z = 1;
  for(int i=0;i<y;i++) z *= x;
  return z;
}
int main(){
  int n,a,i,ki = 1;cin >> n;
  for(i=0;i<n;i++){
    cin >> a;
    ki *= (a%2==0) + 1;
  }
  cout << pow(3,n)-ki << endl;
}