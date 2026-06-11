#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ll N,M;
    cin >> N >> M;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) {
        ll a;
        cin >> a;
        if (i == 0) {
            A.at(i) = a % M;
        }
        else {
            A.at(i) = (A.at(i - 1) + (a % M)) % M;
        }
    }
    map<ll,ll> list;
    for (int i = 0; i < N; i++) {
        list[A.at(i)]++;
    }
    ll ans = 0;
    for (auto lt : list) {
        ans += lt.second * (lt.second - 1) / 2;
        if (lt.first == 0) {
            ans += lt.second;
        }
    }
    cout << ans << endl;
}