#include<iostream>
using namespace std;

int main(){
  int n,a[3001],sum=0;
  cin >> n;
  for(int i=0;i<n;i++){
    cin >> a[i];
    sum+=a[i]-1;
  }
  cout << sum;
}