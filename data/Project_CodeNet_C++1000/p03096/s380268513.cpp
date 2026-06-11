#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;

ll MOD = 1e9 + 7;

int main(){
    int N;
    cin >> N;
    int c[N];
    for(int i = 0; i < N; i++) cin >> c[i];

    vector<int> a;
    a.push_back(c[0]);
    for(int i = 1; i < N; i++){
        if(c[i - 1] != c[i]) a.push_back(c[i]);
    }

    int sz = a.size();

    ll col[200001]; //色iがでたときに足すべき値
    fill(col, col + 200001, 0);

    vector<ll> dp(sz, 0);

    dp[0] = 1;
    col[a[0]]++;
    for(int i = 1; i < sz; i++){
        dp[i] = dp[i - 1];
        dp[i] += col[a[i]];
        col[a[i]] += dp[i - 1];

        dp[i] %= MOD;
        col[a[i]] %= MOD;
    }

    cout << dp[sz - 1] << endl;
    return 0;
}
