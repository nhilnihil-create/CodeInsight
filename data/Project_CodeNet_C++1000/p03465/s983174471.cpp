#include<bits/stdc++.h>
using namespace std;

int n,a[2005],sum;
bitset<4000005> dp;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    dp[0]=1;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
        dp|=dp<<a[i];
    }
    cout<<dp._Find_next(sum-1>>1)<<endl;

    return 0;
}