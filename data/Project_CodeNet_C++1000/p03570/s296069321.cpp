#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
map<int, int> mp;
const int maxn = 202020;
char ch[maxn];
int rem[maxn], dp[maxn];
int main(){
    memset(dp, 127, sizeof(dp));
    dp[0] = 0;
    mp[0] = 0;
    scanf("%s", ch+1);
    int n = strlen(ch+1);
    for(int i = 1; ch[i] != '\0'; i ++){
        rem[i] = rem[i-1] ^ (1 << (ch[i] - 'a'));
    }
    
    for(int i = 1; i <= n; i ++){
        if(mp.find(rem[i]) != mp.end()){
            dp[i] = dp[mp[rem[i]]];
        }
        for(int j = 0; j < 26; j ++){
            if(mp.find(rem[i] ^ (1<<j)) == mp.end())
                continue;
            
            dp[i] = min(dp[i], dp[mp[rem[i] ^ (1<<j)]] + 1);
        }
        mp[rem[i]] = i;
    }
    if(!rem[n])
        dp[n] = 1;
    printf("%d", dp[n]);
    return 0;
}
