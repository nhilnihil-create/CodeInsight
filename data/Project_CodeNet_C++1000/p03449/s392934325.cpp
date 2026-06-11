#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long;
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<vector<int>> a(2,vector<int>(n));
    rep(i,2) rep(j,n) cin>>a[i][j];
    vector<int> num(n+1,0);
    for(int i=1;i<n+1;i++) num[i]+=(num[i-1]+a[0][i-1]);

    int maxv=0;
    rep(i,n){
        int sum=0;
        sum+=num[i+1];
        for(int j=i;j<n;j++){
            sum+=a[1][j];
        }
        maxv=max(maxv,sum);
    } 
    cout<<maxv<<"\n";
    return 0;
}