#include<bits/stdc++.h>
using namespace std;
const int m=1e9+7;
using ll=long long;
void rec(vector<int>&seg,vector<int>v,int pos,int tl,int tr){
     if(tl==tr){
         seg[pos]=v[tl];
         return ;
     }
     int mid=(tl+tr)/2;
     rec(seg,v,2*pos+1,tl,mid);
     rec(seg,v,2*pos+2,mid+1,tr);
     seg[pos]=seg[2*pos+1]+seg[2*pos+2];
     // cout<<pos<<" "<<seg[pos]<<endl;
}
int find(vector<int>&seg,int pos,int tl,int tr,int l,int r){
     // cout<<tl<<" "<<tr<<" "<<l<<" "<<r<<endl;
     if(l>r){
          return 0;
     }
     if(l==tl&&r==tr){
          return seg[pos];
     }
     int mid=(tl+tr)/2;
     return find(seg,2*pos+1,tl,mid,l,min(r,mid))
               +find(seg,2*pos+2,mid+1,tr,max(mid+1,l),r);
}
int main(){
     int n,k;
     cin>>n>>k;
     vector<int>a(n,0);
     bool dp[k+1][2];
     for(int i=0;i<=k;i++){
          dp[i][0]=false;
          dp[i][1]=false;
     }
     for(int i=0;i<n;i++){
          cin>>a[i];
          dp[a[i]][0]=true;
          dp[a[i]][1]=true;
          // cout<<dp[a[i]][1]<<endl;
     }
     
     
     for(int i=1;i<=k;i++){
          for(int j=0;j<n;j++){
               dp[i][0]=dp[i][0]||((i-a[j]>=0)?(!(dp[i-a[j]][1])):false);
               dp[i][1]=dp[i][1]||((i-a[j])>=0?(!(dp[i-a[j]][0])):false);
               
          }
          // cout<<dp[i][0]<<" "<<dp[i][1]<<" "<<i<<" "<<endl;
          
     }
     if(dp[k][0]){
          cout<<"First"<<endl;
          return 0;
     }
     cout<<"Second"<<endl;
     
}