#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll INF = 100000000;
#define rep1(i, n) for (ll i=0; i<(n); i++) 
#define rep2(i, k, n) for (ll i=k; i<(n); i++)

ll N;

//cur = 現在, use = 3,5,7のどれをつかったか, count = 答えになるやつ
void func(ll cur, ll use, ll &count) {
    if (cur > N) return;
    if (use == 0b111) count++;

    func(cur*10+3, use|0b001, count);
    func(cur*10+5, use|0b010, count);
    func(cur*10+7, use|0b100, count);
}

int main() {
    cin >> N;
    ll res = 0;
    func(0,0,res);
    cout << res << endl;
}

