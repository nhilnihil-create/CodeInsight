#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int arr[17];
ll dp[17][150][2];
int sums=0;
ll getsum(int ind, int n, int sum, bool flag){
    if(ind>=n) return sum;
    
    int limit=9;
    if(!flag) limit= arr[ind];
    //flag=true means earlier ther is some smaller digit used so we can take till 9 this time;
    if(dp[ind][sum][flag]!=-1) return dp[ind][sum][flag];
    
    ll res=0;
    for(int i=0;i<=limit;i++){
        if(flag || i<limit)
            res= max(res, getsum(ind+1, n, sum+i, true ));
        else 
            res= max(res, getsum(ind+1, n, sum+i, false));
    }
    return dp[ind][sum][flag]= max(res,dp[ind][sum][flag]);
}

int main(){
    int t=1;
    while(t--){
        ll x; cin >> x;
        string a= to_string(x);
        
        int s=0;
        for(int i=0;i<a.size();i++)for(int j=0;j<150;j++)for(int k=0;k<2;k++) 
            dp[i][j][k]=-1;
        
        for(int i=0;i<a.size();i++) {arr[i]=a[i]-'0'; s += arr[i];}
        ll left=getsum(0, a.size(), 0, 0);

        // for(int i=0;i<b.size();i++)for(int j=0;j<150;j++)for(int k=0;k<2;k++) 
        //     dp[i][j][k]=-1;
        
        // for(int i=0;i<b.size();i++) arr[i]=b[i]-'0';
        // ll right=getsum(0, b.size(), 0, 0);

        // ll ans=right-left+s;
        cout << left << endl;
    }
}