#include <bits/stdc++.h>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <iostream>
#include <bitset>
#include <cassert>
#include <queue>
#include <random>
#include <stack>
#include <iomanip>
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)n; i++)
#define repf(i, a, b) for (ll i = (ll)a; i < (ll)b; i++)
#define repr(i, a, b) for (ll i = (ll)a; i > (ll)b; i--)
#define repv(x, arr) for (auto &x : arr)
#define all(v) (v).begin(), (v).end()
#define vec(name, num) vector<ll> name((num), 0);
#define mp(a, b) make_pair(a, b)
#define op(i) cout << (i) << endl;
#define F first
#define S second
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pdd;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<int> vii;
typedef vector<vii> vvii;
const ll mod = 1e9 + 7;
const int infi = 2147483600;
const ll infl = 1e17;

double calc(int x){
    double s = 0;
    int now = x;
    while (now>0){
        s += now % 10;
        now /= 10;
    }
    return (double)x / s;
}

int ketawa(int x){
    int s = 0;
    int now = x;
    while (now > 0)
    {
        s += now % 10;
        now /= 10;
    }
    return s;
}

bool sunuke(int x){
    repf(i,x+1,x+1000001){
        if (calc(x)>calc(i))
            return false;
    }
    return true;
}

int main()
{
    int k;
    cin >> k;
    int cnt = 1;
    ll bef,now;
    repf(i, 1, 10) cout << i << endl;
    bef = 9;
    k -= 9;
    while (k>0){
        int x = 1;
        while (9*cnt+ketawa(x)>x){
            now = x;
            rep(j, cnt){
                now *= 10;
                now += 9;
            }
            if (now<=bef){
                x++;
                continue;
            }
            cout << now << endl;
            x++;
            k--;
            bef = now;
            if (k==0)
                return 0;
        }
        cnt++;
    }
}