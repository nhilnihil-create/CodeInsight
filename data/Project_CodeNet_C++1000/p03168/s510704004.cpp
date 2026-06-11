//
// Created by Harshit on 21-08-2020.
//

//
// Created by Harshit on 21-08-2020.
//
#include "bits/stdc++.h"
using namespace std;
int main(){
    int n;
    cin>>n;
    vector <double> pro(n);
    vector <double> dp(n+1,0.0);

    vector <double> new_dp;
    for(int i=0;i<n;i++)
        cin>>pro[i];

    dp[0]=1-pro[0];
    dp[1]=pro[0];

    for(int i=1;i<n;i++){
        new_dp.assign(n+1,0.0000);
        for(int j=0;j<=n;j++){
            if(j>i+1)
                new_dp[j]=0;
            else{
                new_dp[j]+=(double)(dp[j]*(1.0-pro[i]));
                if(j>0)
                    new_dp[j]+=(double)(dp[j-1]*pro[i]);
            }
        }
        dp=new_dp;
    }
    double res=0;

    for(int i=0;i<=n;i++){
        if(n-i<i){
            res+=dp[i];
        }
    }
    cout<<setprecision(20);
    cout<<res<<endl;

}

