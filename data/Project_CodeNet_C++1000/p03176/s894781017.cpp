#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;

int a[220000];
long dp[220000];
long BIT[220000];
vector<P> flowers;

void set_val(long *bit, int idx, long val){
    idx++;
    while(idx < 220000){
        bit[idx] = max(bit[idx], val);
        idx += idx & -idx;
    }
}

long max_val(long *bit, int idx){
    long res = 0;
    idx++;
    while(idx){
        res = max(res, bit[idx]);
        idx -= idx & -idx;
    }
    return res;
}

int main(){
    int n, h;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> h;
        flowers.push_back(P(h, i));
    }
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(flowers.begin(), flowers.end());
    long ans = 0;
    for(auto p: flowers){
        int i = p.second;
        dp[i] = max_val(BIT, i -1) + a[i];
        set_val(BIT, i, dp[i]);
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
}