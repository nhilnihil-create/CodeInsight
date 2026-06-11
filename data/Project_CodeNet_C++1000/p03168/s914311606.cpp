#include<bits/stdc++.h>
using namespace std;

vector<vector<double>> dp;
double find(int i,vector<double> &v,int rem){
    double ans=0;
    if(dp[i][rem]!=-1)return dp[i][rem];
    if(i==v.size()-1){
        ans+=v[i];
        if(rem>0){
            ans+=(double)1-v[i];
        }
        return dp[i][rem]=ans;
    }
    ans+=find(i+1,v,rem)*v[i];
    if(rem>0)
    ans+=find(i+1,v,rem-1)*((double)1-v[i]);
    return dp[i][rem]=ans;
}

int main(){
    
    int n;
    cin>>n;
    dp.clear();
    dp.resize(n+1,vector<double>(n-(n/2),-1));
    vector<double> v(n,-1);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    //cout<<find(0,v,n-(n/2)-1)<<endl;
    double ans=find(0,v,n-(n/2)-1);
    // printf("%lf\n",ans);
    //std::cout << std::fixed;
    std::cout << std::setprecision(10);
    std::cout << ans<<endl;
    
    return 0;
}