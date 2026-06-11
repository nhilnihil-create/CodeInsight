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
    vector<ll> a(N, 0);
    ll far = 0;
    Rep (i, N) {
        cin >> a[i];
        if (abs(a[i]) > abs(a[far])) {
            far = i;
        }
    }

    ll m = 2 * N - 1;
    cout << m << "\n";
    Rep (i, N) {
        cout << far+1 << " " << i+1 << "\n";
    }

    if (a[far] > 0) {
        Rep (i, N-1) {
            cout << i+1 << " " << i+2 << "\n";
        }
    } else {
        Rep (i, N-1) {
            cout << N-i << " " << N-i-1 << "\n";
        }
    }

    cout << flush;
}