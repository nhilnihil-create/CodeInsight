#include<iostream>
using namespace std;
bool is_prime(int m) {
  for(int i=2;i*i<=m;i++)if(m%i==0)return false;
  return true;
}
int main(void){
  int n;
  cin>>n;
  for(int i=11;i<=55555;i+=5){
    if(is_prime(i)){
      if(i!=11)cout<<" ";
      cout<<i;
      n--;
    }
    if(n==0)break;
  }
  cout<<endl;
  return 0;
}
