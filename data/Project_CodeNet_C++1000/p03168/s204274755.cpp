#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long;

int main(){
    int n;
    cin>>n;
    vector<double> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    vector<vector<double>> dat(n+1,vector<double>(n+2));
    dat[1][0]=1-a[1];
    dat[1][1]=a[1];
    for(int i=2;i<=n;i++){
        for(int j=0;j<=i;j++){
            if(j==0){
                dat[i][j]=dat[i-1][j]*(1-a[i]);
            }
            else dat[i][j]=(dat[i-1][j]*(1-a[i])+(dat[i-1][j-1]*a[i]));
        }
    }
    double ans=0;
    for(int i=n/2+1;i<=n;i++){
        ans += dat[n][i];
    }
    printf("%.10f",ans);
}