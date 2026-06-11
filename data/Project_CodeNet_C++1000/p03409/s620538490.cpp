#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7/*998244353*/;
const ll INF = 1LL << 60;
ll mod_pow(ll, ll, ll); ll mod_fact(ll, ll); ll mod_inv(ll, ll); ll gcd(ll, ll); ll lcm(ll, ll);
//
int main(){
    int n;
    cin >> n;
    vector<pair<int, int>> pf, ps;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        pf.emplace_back(a, b);
    }
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        ps.emplace_back(a, b);
    }
    sort(ps.begin(), ps.end());
    sort(pf.begin(), pf.end());
    vector<bool> chosen(n);
    int cnt = 0;
    for(int i = 0; i < n; i++){
        int x = ps[i].first;
        int y = ps[i].second;
        int mxy = -1;
        int idx = -1;
        for(int j = 0; j < n; j++){
            if(chosen[j]) continue;
            if(pf[j].first < x && pf[j].second > mxy && pf[j].second < y) {mxy = pf[j].second; idx = j;}
        }
        if(idx != -1) {chosen[idx] = true; cnt++;}
    }
    cout << cnt;
}