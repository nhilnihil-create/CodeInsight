#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 2e5 + 100;
char str[maxn];
int a[maxn];
int dp[(1<<26)];
int main()
{
    cin>>str;
    int L = strlen(str), ans = 0;
    for(int i = 0; i < L; i++){
        ans ^= (1<<(str[i] - 'a'));
        a[i] = ans;
    }
    memset(dp, 1, sizeof(dp));
    for(int i = 0; i < L; i++){
        int ok = 0;
        for(int j = 0; j < 26; j++) if(a[i] == 0 || (a[i]^(1<<j)) == 0) { dp[a[i]] = 1; ok = 1; break; }
        if(ok) continue;
        for(int j = 0; j < 26; j++)
            dp[a[i]] = min(dp[a[i]^(1<<j)]+1, dp[a[i]]);
        //  cout<<dp[a[i]]<<endl;
    }
    cout<<dp[a[L-1]]<<endl;
    return 0;
}
