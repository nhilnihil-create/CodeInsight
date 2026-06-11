#include <bits/stdc++.h>
using namespace std;
#define all(a) a.begin(),a.end()
#define INT_INF 0x3f3f3f3f
#define LL_INF 0x3f3f3f3f3f3f3f3f
#define MOD 1000000007
#define MOD2 1494318097
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define nl '\n'
typedef long long ll;
typedef pair<int,int> pii;
const int maxn = 200005;

int n,a[maxn],pos[maxn],dp[maxn],res;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        pos[a[i]] = i;
    }
    for(int i=1; i<=n; i++){
        if(i > 1 && pos[i-1] < pos[i]) dp[i] = dp[i-1]+1;
        else dp[i] = 1;
        res = max(res,dp[i]);
    }
    cout << n-res << nl;
}