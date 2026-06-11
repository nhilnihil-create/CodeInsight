#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e3+5;
const int mod=1e9+7;
bitset<maxn*maxn>dp;
int n,a,s;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    dp[0]=1;
    for(int i=1;i<=n;i++){
        cin>>a;
        dp|=dp<<a;
        s+=a;
    }
    for(int i=(s+1)/2;i<=s;i++) 
        if(dp[i]){
            cout<<i<<endl;
            break;
        }
    return 0;
}