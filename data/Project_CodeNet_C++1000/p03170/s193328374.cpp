#include<bits/stdc++.h>
using namespace std;
int main(){
int n , k ;
cin>>n>>k;
vector<int>v(n);
for(int i = 0 ; i < n ; i++)cin>>v[i];
sort(v.begin(),v.end());
vector<int>dp(k+1,1);
for(int i = 0 ; i < v.front();i++){
dp[i]=-1;
}
for(int i = v.front() ; i <= k ; i++ ){
for(int j = 0 ; j < v.size() ; j++){
if(i-v[j]>=0){
dp[i]=min(dp[i],dp[i-v[j]]);
}
}
dp[i]*=(-1);
}
if(dp[k]==1)cout<<"First";
else cout<<"Second";

}
