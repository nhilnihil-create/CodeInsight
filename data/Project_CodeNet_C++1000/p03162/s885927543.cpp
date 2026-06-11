#include<iostream>
#include<unordered_map>
#include<algorithm>
using namespace std;
int dp[100001][4];
int recur(int n,int i,int z,int a[],int b[], int c[]){
if(i==n){
    return 0;
}
if(dp[i][z]!=0){
    return dp[i][z];
}
else{
    int ans=0;
    if(z==1){
        ans=max(recur(n,i+1,2,a,b,c),recur(n,i+1,3,a,b,c));
        ans+=a[i];
    }
    else if(z==2){
        ans=max(recur(n,i+1,1,a,b,c),recur(n,i+1,3,a,b,c));
        ans+=b[i];
    }
    else if(z==3){
        ans=max(recur(n,i+1,1,a,b,c),recur(n,i+1,2,a,b,c));
        ans+=c[i];
    }
    dp[i][z]=ans;
    return ans;
    
}
}
int main(){
    int n;
    cin>>n;
    int a[n],b[n],c[n];
    for(int i=0;i<100001;i++){
        for(int j=0;j<4;j++){
            dp[i][j]=0;
        }
    }
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i]>>c[i];
    }
cout<<max(max(recur(n,0,1,a,b,c),recur(n,0,2,a,b,c)),recur(n,0,3,a,b,c))<<endl;
    
    return 0;

}