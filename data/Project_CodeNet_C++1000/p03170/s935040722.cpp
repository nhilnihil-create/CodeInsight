#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000 * 1000 + 10;
const long long INF = 1LL * 1000 * 1000 * 1000 * 1000 * 1000 * 1000 + 10;

bool is_first_dp[MAXN];

int stone[200];
int n, k;

bool update(int t)
{
    //cerr << "k :" << t << endl;
    bool result = false;

    for(int i = 0; i < n; i++){
        if(stone[i] > t) break;
        if(!is_first_dp[t - stone[i]]) result = true;
        //cerr << stone[i] << ' ' << result << endl;
    }
    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //cout << fixed << setprecision(10);

    cin >> n >> k;

    for(int i = 0; i < n; i++) cin >> stone[i];

    is_first_dp[0] = false;

    for(int i = 1; i <= k; i++) is_first_dp[i] = update(i);

    if(is_first_dp[k]){
        cout << "First" << endl;
    }
    else{
        cout << "Second" << endl;
    }

    return 0;
}

