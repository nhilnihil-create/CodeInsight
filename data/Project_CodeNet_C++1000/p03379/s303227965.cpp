#include <bits/stdc++.h>

using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define ll long long int

int main(){
int n;
cin>>n;
ll X[n],Y[n];
rep(i,n){
cin>>X[i];
Y[i]=X[i];
}
sort(Y,Y+n);

double H=((double)Y[n/2-1]+(double)Y[n/2])/2;
//cout<<H<<endl;
rep(i,n){
if(X[i]>=H){
  cout<<Y[n/2-1]<<endl;
}else
{
  cout<<Y[n/2]<<endl;
}


}
  return 0;
}
