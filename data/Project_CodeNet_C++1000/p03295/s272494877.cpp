#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;
const ll INF = 1LL << 60;
ll mod_pow(ll, ll, ll); ll mod_fact(ll, ll); ll mod_inv(ll, ll); ll gcd(ll, ll); ll lcm(ll, ll);
//
int main(){
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> scheduling;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        scheduling.emplace_back(b, a);
    }
    sort(scheduling.begin(), scheduling.end());
    int cur = INT_MIN;
    int cnt = 0;
    for(int i = 0; i < m; i++){
        auto p = scheduling[i];
        if(cur < p.second){
            cnt++;
            cur = p.first - 1;
        }
    }
    cout << cnt;
}