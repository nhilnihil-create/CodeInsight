#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,sumb=0,a[101],b[101];
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  for(int i=0;i<n;i++){
    cin>>b[i];
    sumb+=b[i];
  }
  int sumA=0;
  int mx=0;
  for(int i=0;i<n;i++){
   int sum=(sumA+a[i]+sumb);
    sumA+=a[i];
    sumb-=b[i];
    mx=max(mx,sum);
  }
  cout<<mx<<endl;
}
    