#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back

typedef long long ll;
typedef pair<int, int> pi;

const int maxn = 2005;

bitset<maxn * maxn> dp[2];
int a[maxn];

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    memset(dp, false, sizeof(dp));
    int n;
    cin >> n;
    int sum = 0;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        sum += a[i];
    }
    shuffle(a + 1, a + 1 + n, rng);
    dp[0].set(0);
    for(int i = 1;i <= n;i++){
        int cur = i & 1;
        int pre = cur ^ 1;
        dp[cur] = dp[pre] | (dp[pre] << a[i]);
    }
    for(int i = 0;i <= sum;i++){
        if(dp[n & 1].test(i)){
            if(sum - i <= i){
                cout << i << endl;
                return 0;
            }
        }
    }
    return 0;
}
