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
using vvvi = vector<vi>;
const ll MOD = 1e9 + 7;
vi alphabet = { 'a','b','c','d','e','f','g','h','i','j','k','l','m',
               'n','o','p','q','r','s','t','u','v','w','x','y','z' };




int main() {
    int n, h;
    cin >> n >> h;
    vi a(n);
    vi b(n);
    vi copy(n);
    rep(i, n) {
        cin >> a[i];
        cin >> b[i];
        copy[i] = a[i];
    }
    sort(copy);
    riverse(copy);
    int maxa = copy[0];
    int sumb = 0;
    int count = 0;
    sort(b);
    riverse(b);
    for (int x : b) {
        if (x > maxa) {
            h -= x;
            count++;
            if (h <= 0)break;
        }
    }
    if (h <= 0) cout << count << endl;
    else {
        if (h % maxa != 0) {
            count += h / maxa;
            count++;
        }
        else count += h / maxa;
        cout << count << endl;
    }
}