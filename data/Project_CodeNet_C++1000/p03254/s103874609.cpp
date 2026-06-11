#include<bits/stdc++.h>
using namespace std;
int main(){
  unsigned long long n,x;
  cin >> n >> x;
  unsigned long long a[n]={};
  for(unsigned long long i=0;i<n;i++){
    cin >> a[i];
  }
  unsigned long long sum=0ull;
  sort(a,a+n);
  for(unsigned long long i=0;i<n;i++){
    sum+=a[i];
    if(x==sum){
      cout << i+1ull << endl;
      break;
    }
    if(x<sum){
      cout << i << endl;
      break;
    }
    if(i==n-1){
      cout << i << endl;
    }
    
  }
}
