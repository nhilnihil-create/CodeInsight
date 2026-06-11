#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int n; cin >> n;
    bitset<4004000>dp;
    dp[0]=1;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        int a; cin >> a;
        sum=sum+a;
        dp |= (dp<<a);
    }
    int ans=(sum+1)/2;
    while(!dp[ans])
    {
        ans++;
    }
    cout << ans << endl;
}