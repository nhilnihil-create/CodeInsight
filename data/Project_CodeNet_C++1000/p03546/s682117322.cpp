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
#define repp(i, n) for(int i = 1; i <= n; i++)
#define sort(v) sort((v).begin(), (v).end())
#define riverse(v) reverse((v).begin(), (v).end())
#define pb push_back
#define mp make_pair
#define all(a)  (a).begin(),(a).end()
using vi = vector<int>;
using vs = vector<string>;
using vll = vector<ll>;
using vvi = vector<vi>;
const ll MOD = 1e9 + 7;
vi alphabet = { 'a','b','c','d','e','f','g','h','i','j','k','l','m',
               'n','o','p','q','r','s','t','u','v','w','x','y','z' };





int main() {
    int H, W;
    cin >> H >> W;
    vvi c(10, vi(10));
    rep(i, 10) {
        rep(j, 10) cin >> c[i][j];
    }
    vi counter(10,0);
    rep(i, H* W) {
        int x;
        cin >> x;
        rep(j, 10) {
            if (x == j)counter[j]++;
        }
    }

    vi per(10);
    rep(i, 10) per[i] = i;
    vi kouho(10,200000);
    do {
        int x = per[0];
        int sum = 0;
        int mae;
        int ima = x;
        int i = 0;
        while (ima != 1) {
            mae = ima;
            ima = per[i];
            i++;
            sum += c[mae][ima];
        }
        if (sum < kouho[x]) kouho[x] = sum;
    } while (next_permutation(per.begin(), per.end()));
    

    ll ans = 0;
    rep(i, 10) {
        ans += kouho[i] * counter[i];
    }
    cout << ans << endl;
}