#include <bits/stdc++.h>

using namespace std;
#define rep(i,n) for(int i=1;i<n+1;i++)
#define ll long long int

int main(){
int n;
cin>>n;
int a[n],sum=0;
a[0]=0;a[n+1]=0;
rep(i,n){
cin>>a[i];
sum+=abs(a[i-1]-a[i]);
}
sum+=abs(a[n]-a[n+1]);

rep(i,n){

cout<<sum-abs(a[i-1]-a[i])-abs(a[i]-a[i+1])+abs(a[i-1]-a[i+1])<<endl;

}

  return 0;
}
