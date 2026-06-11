#include <bits/stdc++.h>
using namespace std;
int main(){
  long long n,ans=0;
  cin>>n;
  bool flg=0;
  for(long i=1;i<n;i++){
  	if(i*i+i<n && n%i==0){
      ans+=(n-i)/i;
    }
    if(i*i+i>=n) flg=1;
    if(flg) break;
  }
  cout<<ans<<endl;
}