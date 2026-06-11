#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n,k=0;
  bool a[40];
  cin>>n;
  if(n==0)cout<<0<<endl;
  else {
    for(int i=0;i<40;i++){
      if(n%2==0){
        a[i]=false;
        n/=2;
      }
      else{
        a[i]=true;
        if(i%2==0)n=(n-1)/2;
        else n=(n+1)/2;
      }
      k++;
      if(n==0)break;
    }
    for(int i=k-1;i>=0;i--){
      cout<<a[i];
    }
    cout<<endl;
  }
}
