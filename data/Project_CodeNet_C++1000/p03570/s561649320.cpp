#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 2e5 + 100;
char str[maxn];
int a[maxn];
int dp[(1<<26)];

void print(int x)
{
    while(x){
        cout<<x%2;
        x/=2;
    }
    cout<<endl;
}

int main()
{
    cin>>str;
    int L = strlen(str), ans = 0;
    for(int i = 0; i < L; i++){
        ans ^= (1<<(str[i] - 'a'));
        a[i] = ans;
    }
/*    for(int i = 0;i<L;i++){
        cout<<a[i]<<"  -> ";
        print(a[i]);
    }
*/

    memset(dp, 1, sizeof(dp));
    for(int i = 0; i < L; i++){
        int ok = 0;
        for(int j = 0; j < 26; j++) if(a[i] == 0 || (a[i]^(1<<j)) == 0) { dp[a[i]] = 1; ok = 1; break; }
        //cout<<a[i]<<" "<<dp[a[i]]<<endl;
        if(ok) continue;
        for(int j = 0; j < 26; j++)
            dp[a[i]] = min(dp[a[i]^(1<<j)]+1, dp[a[i]]);
    }
    cout<<dp[a[L-1]]<<endl;
    return 0;
}
