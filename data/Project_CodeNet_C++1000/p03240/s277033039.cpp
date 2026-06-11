#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>
#include <numeric>
#include <cmath>
#include <iomanip> //cout << fixed << setprecision(15) << << endl;
#include <cassert>
//#include "atcoder/all"

using namespace std;
//using namespace atcoder;

typedef long long ll;

#define pb push_back
#define rep(i, n) for(int i=0;i<(n);i++)
#define REP(i, n) for(int i=1;i<=(n);i++)
#define P pair<int,int>
template <typename T> T &chmin(T &a, const T &b) { return a = min(a, b); }
template <typename T> T &chmax(T &a, const T &b) { return a = max(a, b); }

int mx8[] = {0, 0, 1, -1, -1, 1, -1, 1};
int my8[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int mx4[] = {1, -1, 0, 0};
int my4[] = {0, 0, -1, 1};

const int MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);

    int n; cin >> n;
    vector<ll> x(n),y(n),h(n);
    rep(i,n) cin >> x[i] >> y[i] >> h[i];
    bool ok;

    for(ll cx = 0; cx <= 100; cx++)
    {
        for(ll cy = 0; cy <= 100; cy++)
        {
            ok = false;

            ll H, minH = 1e18, maH = 0, miH = 1e18;
            for(int i = 0; i < n; ++i)
            {
                H = h[i] + abs(x[i]-cx) + abs(y[i]-cy);
                if(h[i])
                {
                    chmin(miH,H);
                    chmax(maH,H);
                }
                else
                {
                    chmin(minH,H);
                }
            }
            if(miH == maH && miH <= minH) ok = true;
            if(ok)
            {
                cout << cx << " " << cy << " " << miH << endl;
                return 0;
            }
        }
    }
}