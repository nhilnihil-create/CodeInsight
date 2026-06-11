#include<iostream>
using namespace std;
int main(){
  long long n,k;cin >> n >> k;
  long long a[2];
  a[0] = n/k;
  if(k%2==0 && n>=k/2) a[1] = 1+(n-k/2)/k;
  else a[1] = 0;
  cout << a[0]*a[0]*a[0]+a[1]*a[1]*a[1] << endl;
}
  