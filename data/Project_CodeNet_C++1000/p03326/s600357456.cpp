#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    long long x[n][3];
    for(int i=0;i<n;i++)for(int j=0;j<3;j++)cin>>x[i][j];
    long long ma=0;
    for(int i=0;i<8;i++){
        int I=i;
        long long status[n]={};
        for(int j=0;j<3;j++){
            if(I%2)for(int k=0;k<n;k++)status[k]+=x[k][j];
            else for(int k=0;k<n;k++)status[k]-=x[k][j];
            I/=2;
        }
        sort(status,status+n,greater<long long>());
        long long X=0;
        for(int i=0;i<m;i++)X+=status[i];
        ma=max(ma,X);
    }
    cout<<ma<<endl;
    return 0;
}