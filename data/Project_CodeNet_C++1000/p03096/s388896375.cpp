#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> v;
long long dp[200005];
long long cache[200005];
long long MOD = 1e9+7;

int main(){
    cin >> N;
    v.push_back(0);
    for(int i = 1; i<=N; i++){
        int n;
        cin >> n;
        v.push_back(n);
    }
    v.erase(unique(v.begin(), v.end()), v.end());
    N = v.size();
    N--;
    dp[0] = 1;
    for(int i = 1; i<=N; i++){
        cache[v[i]] += dp[i-1];
        cache[v[i]] %= MOD;
        dp[i] = cache[v[i]];
    }
    cout << dp[N] << endl;
}
