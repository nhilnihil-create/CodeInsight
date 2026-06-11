#include <iostream>
using namespace std;
int n,c[200001],s[200001];
long long dp[200001],INF=1000000007;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>c[i];
        if(c[i]==c[i-1])i--,n--;
    }dp[0]=1;
    for(int i=1;i<=n;i++){
        dp[i]=(dp[i-1]+s[c[i]])%INF;
        s[c[i]]+=dp[i-1];
        s[c[i]]%=INF;
    }
    cout<<dp[n]<<endl;
}