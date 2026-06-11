#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const int BIG = 2e9 + 55;
const int maxN = 200 + 5;

int n;
int a[maxN];
int memo[maxN][maxN];
bool calc[maxN][maxN];

int dp(int i, int curH){
    if(i == n){
        return (curH != a[i]);
    }

    if(calc[i][curH]){
        return memo[i][curH];
    }

    int ans = n;
    for(int nxtH = 1; nxtH < maxN; nxtH++){
        if(curH != nxtH){
            ans = min(ans, dp(i + 1, nxtH) + (curH != a[i]));
        }
    }

    calc[i][curH] = true;
    return (memo[i][curH] = ans);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    int mn = n;

    for(int curH = 1; curH < maxN; curH++){
        mn = min(mn, dp(1, curH));
    }

    cout << mn << '\n';

    return 0;
}