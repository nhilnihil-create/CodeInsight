#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    map<ll, ll> x;

    for(int i = 0; i < N; i++) {
        ll a;
        cin >> a;
        x[a]++;
    }

    ll ans = 0;

    for(auto i = begin(x); i != x.end(); i++) {
        ll front = i -> first;
        ll back = i -> second;
        if(front < back) {
            ans += back - front;
        } else if(front > back) {
            ans += back;
        }
    }

    cout << ans << endl;
}