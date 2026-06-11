#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1000000007LL;
long long GCD(long long a, long long b){return b == 0 ? a : GCD(b, a % b);}
long long fast_exp(long long base, long long exp, long long mod = MOD) {
    long long tot = 1;
    for(;exp > 0;exp >>= 1) {
       if((exp & 1) == 1) tot = tot * base % mod;
       base = base * base % mod;
    }
    return tot;
}

int arr[2001], n, k, q;

int helper(int minimum){
    vector<int> low = {}, cur = {};
    for(int i = 0; i < n; ++i){
        if(arr[i] >= minimum) cur.push_back(arr[i]);
        if(i == n - 1 || arr[i] < minimum){
            int grab = cur.size() - k + 1;
            sort(cur.begin(), cur.end());
            for(int j = 0; j < grab; ++j)
                low.push_back(cur[j]);
            cur.clear();
        }
    }
    sort(low.begin(), low.end());
    if(low.size() < q)
        return 2e9;
    return low[q - 1] - low[0];
}

int main(){

    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> n >> k >> q;

    for(int i = 0; i < n; ++i) cin >> arr[i];

    int best = 2e9;

    for(int i = 0; i < n; ++i)
        best = min(best, helper(arr[i]));

    cout << best << "\n";

    return 0;

}
