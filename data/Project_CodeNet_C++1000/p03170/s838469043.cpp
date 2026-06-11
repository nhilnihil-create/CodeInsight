#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define        optimize           ios::sync_with_stdio(0); cin.tie(0);
#define PI    acos(-1.0)
#define pb push_back
#define YES cout<<"YES"<<endl;
#define NO cout<<"NO"<<endl;
#define RESET(a, b) memset(a, b, sizeof(a))
#define pii pair <int, int>
#define gcd(a, b) __gcd(a, b)
#define min3(a, b, c) min(c, min(a, b))
#define max3(a, b, c) max(c, max(a, b))

#define        MX        200005

int ara[MX];
int dp[MX];

int main()
{
    optimize
    int n, k;
    cin>>n>>k;

    for(int i = 0; i < n; i++){
        cin>>ara[i];
    }

    for(int i = 1; i <= k; i++){
        for(int j = 0; j < n; j++){
            if(i-ara[j] >= 0 && !dp[i-ara[j]]){
                dp[i] = 1;
            }
        }
    }
    puts(dp[k] ? "First" : "Second");
}
