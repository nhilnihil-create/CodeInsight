#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> P;

int main(){
    int N;
    cin >> N;
    vector<ll> a(N);
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        cin >> a.at(i);
        while (a.at(i) % 2 == 0) {
            ans++;
            a.at(i) /= 2;
        }
    }

    cout << ans << endl;
    return 0;
}
