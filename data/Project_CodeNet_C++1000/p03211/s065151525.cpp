#include <bits/stdc++.h>
using namespace std;

int main(){
  long long int n;
  cin >> n;
  long long int k=1;
  long long int x=n;
  while(x>=10){
    x/=10;
    k++;
  }
  
  long long int ans=1000;
  long long int a=1;
  for(long long int i=0;i<k-2;i++) a*=10;
  
  for(long long int i=0;i<k-1;i++){
    ans=min(ans,max(753-n/a%1000,n/a%1000-753));
    a/=10;
  }
  cout << ans << endl;
}