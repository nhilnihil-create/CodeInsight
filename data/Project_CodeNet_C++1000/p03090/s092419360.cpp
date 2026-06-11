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

    ll M = N * (N-1) / 2 - N / 2;
    cout << M << "\n";
    ll p;
    if (N % 2 == 0) {
        p = N + 1;
    } else {
        p = N;
    }

    for (ll i = 1; i <= N; i++) {
        for (ll j = i+1; j <= N; j++) {
            if (i + j == p) continue;
            cout << i << " " << j << "\n";
        }
    }
}