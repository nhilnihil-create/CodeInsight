#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

bool prime_test(int n){
  bool is_prime=true;
  if(n==1)is_prime=false;
  for(int i=2;i*i<=n;i++){
    if(n%i==0){
      is_prime=false;
      break;
    }
  }
  return is_prime;
}

int main(){
  int a[100010]={};
  int s[100010]={};
  for(int i=1;i<100001;i++){
    if(prime_test(i) && prime_test((i+1)/2) && i%2==1)a[i]++;
    s[i]=s[i-1]+a[i];
  }

  int q;
  cin >> q;
  for(int i=0;i<q;i++){
    int r,l;
    cin >> l >> r;
    cout << s[r]-s[l-1] <<endl;
  }
 
}