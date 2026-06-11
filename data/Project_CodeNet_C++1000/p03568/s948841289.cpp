#include<bits/stdc++.h>
using namespace std;

int main(){
  int n; cin>>n;
  int a[n];
  int even=0;
  for(int i=0;i<n;i++){
    cin>>a[i];
    if(a[i]%2==0) even++;
  }
  long long ans=1;
  for(int i=0;i<n;i++) ans*=3;
  long long temp=1;
  for(int i=0;i<even;i++) temp*=2;
  cout<<ans-temp<<endl;
}