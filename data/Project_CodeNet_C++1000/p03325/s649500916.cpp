#include<iostream>
using namespace std;

int main(){
  int n;
  cin>>n;
  int sum = 0;
  while(n--){
    int temp;
    cin>>temp;
    while(temp%2==0){
      sum++;
      temp/=2;
    }
  }
  cout<<sum;
}