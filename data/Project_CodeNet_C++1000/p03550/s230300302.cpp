#include<iostream>
#include<iomanip>
#include<cstdio>

#include<vector>
#include<queue>
#include<set>
#include<map>
#include<string>

#include<algorithm>
#include<cmath>
#include<numeric>

using namespace std;
typedef long long ll;
template <class T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return 1;} return 0;}
template <class T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return 1;} return 0;}


int main() {
    ll N, Z, W; cin >> N >> Z >> W;
    vector<ll> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];

    if (N == 1) {
        cout << abs(a[0]-W) << endl; return 0;
    }
    cout << max(abs(a[N-1]-W), abs(a[N-1]-a[N-2])) << endl;
}
