#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <algorithm>
#include <cstdio>
#include <iomanip>
#include <queue>
#include <deque>
#include <stack>
#include <fstream>
#include <cmath>

#define ll int64_t
#define Rep(i, n) for (ll i = 0; i < n; i++)
using namespace std;
typedef vector<ll> vec;
typedef vector<vec> mat;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N;
    cin >> N;
    vector<string> S(N);
    Rep (i, N) {
        cin >> S[i];
    }

    ll ans = 0;
    Rep (i, N) {
        ans += N;
        Rep (j, N) {
            Rep (k, N) {
                if (S[(i+j)%N][k] != S[(i+k)%N][j]) {
                    ans -= N;
                    j = k = N;
                }
            }
        }
    }

    cout << ans << "\n";
}