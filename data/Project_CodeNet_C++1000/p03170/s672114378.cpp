#include<bits/stdc++.h>
using namespace std;
main(){
long long int n,k;
cin>>n>>k;
long long int a[n];
for( int i=0;i<n;i++)cin>>a[i];

bool dp[k+1];
memset(dp,false,sizeof(dp));

//dp[0]=true;
for(int i=1;i<=k;i++){

for(int j=0;j<n;j++){

if(i>=a[j]&&(!(dp[i-a[j]])))dp[i]=true;


//cout<<i<<dp[i]<<endl;

if(i<a[j])break;

}
}

if(dp[k])cout<<"First";
else { cout<<"Second";}








}
