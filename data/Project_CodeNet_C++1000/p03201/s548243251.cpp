#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<utility>
#include<algorithm>
#include<cstdio>
#include<iomanip>
#include<queue>
#include<stack>

#define ll int64_t
#define Rep(i, n) for (ll i = 0; i < n; i++)

using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N;
    cin >> N;
    vector<ll> A(N);
    multiset<ll> balls;
    Rep (i, N) {
        cin >> A[i];
        balls.insert(-A[i]);
    }

    ll ans = 0;
    while (balls.size()) {
        ll target = *balls.begin();
        balls.erase(balls.begin());
        target *= -1;
        // cout << target << endl;
        ll p = 1;
        while (p <= target) {
            p *= 2;
        }

        auto itr = balls.find(target-p);
        if (itr != balls.end()) {
            ans++;
            balls.erase(itr);
        }
    }

    cout << ans << endl;
}