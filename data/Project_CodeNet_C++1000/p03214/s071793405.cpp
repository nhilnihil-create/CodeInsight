#include <bits/stdc++.h>
using namespace std;
int main(){
  int N,S=0,m=0;cin>>N;int a[N];
  for(int i=0;i<N;i++){
    cin>>a[i];
    S+=a[i];
    a[i]*=N;
  }
  for(int i=0;i<N;i++)a[i]=abs(a[i]-S);
  for(int i=1;i<N;i++){
    if(a[m]>a[i])m=i;
  }
  cout<<m<<endl;
}