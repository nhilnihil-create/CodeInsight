#include <numeric>
#include <iostream>
#include <array>
#include <string>
#include <vector>
#include <cassert>
#include <algorithm>
#include <math.h> 
#include <set>
#include <map>
#include <utility>
#include <deque>
#include <queue>


using namespace std;

#define ll long long int
#define rep(i, n) for(ll i = 0; i < n; i++)
#define repp(i, n) for(ll i = 1; i <= n; i++)
#define sort(v) sort((v).begin(), (v).end())
#define riverse(v) reverse((v).begin(), (v).end())
#define pb push_back
#define mp make_pair
#define all(a)  (a).begin(),(a).end()
using vi = vector<int>;
using vs = vector<string>;
using vll = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
const ll MOD = 1e9 + 7;
vi alphabet = { 'a','b','c','d','e','f','g','h','i','j','k','l','m',
               'n','o','p','q','r','s','t','u','v','w','x','y','z' };

int main() {
    int H, W, D;
    cin >> H >> W >> D;
    vvi A(H + 1, vi(W + 1));
    vector<pair<int, int>> B(H * W + 1);
    rep(i, H) {
        rep(j, W) {
            int a;
            cin >> a;
            B[a] = mp(i + 1, j + 1);
        }
    }
    int Q;
    cin >> Q;
    vi L(Q);
    vi R(Q);
    rep(i, Q) {
        cin >> L[i];
        cin >> R[i];
    }

    vvi dis(D);
    rep(i, D) {
        int sum = 0;
        int x = i;
        if (i == 0)x = 0;
        dis[i].push_back(0);
        while (x + D <= H * W) {
            int x1 = B[x].first;
            int y1 = B[x].second;
            int x2 = B[x + D].first;
            int y2 = B[x + D].second;
            sum += abs(x1 - x2) + abs(y1 - y2);
            dis[i].push_back(sum);
            x += D;
        }
    }


    rep(i, Q) {
        int a = L[i] / D;
        int b = L[i] % D;
        int c = R[i] / D;
        int ans;
        if (b != 0) {
            ans = dis[b][c] - dis[b][a];
        }
        else {
            ans = dis[b][c] - dis[b][a];
        }
        cout << ans << endl;
    }
}