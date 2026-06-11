
#include<iostream>
using namespace std;
int main() {
  int n;
  cin>>n;
  int j;
  int k;
  for(int i = 10;n % i <= n;i = i * 10){
    if(i == 10){
      j = n % i;
      continue;
    }
    k = n % (i / 10);
    j = (n % i - k) / (i / 10) + j;
    if (n % i == n){
      break;
    }
  }
  if(n % j == 0){
    cout<<"Yes"<<endl;
    return 0;
  }else{
    cout<<"No"<<endl;
    return 0;
  }
  }