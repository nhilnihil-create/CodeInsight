#include<bits/stdc++.h>
using namespace std;
int main(){
  long long n;
  cin>>n;
  int ans=0;
  int i=1;
  for(int i=1;i<=sqrt(n);i++){
    ans=i*i;
  }
  cout<<ans<<endl;
}