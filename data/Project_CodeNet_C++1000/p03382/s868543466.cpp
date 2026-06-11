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

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repf(i, a, b) for (int i = (int)a; i < (int)b; i++)
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

const ll mod = 1e9 + 7;
const ll infl = 1e17;

typedef unsigned long long ull;

int main()
{
    ll n;
    cin >> n;
    vector<ll> A(n);
    rep(i, n) cin >> A[i];
    sort(all(A));
    ll aj = A.back();
    ll now = 0;
    ll ai = 0;
    rep(i,n-1){
        if (min(aj-A[i],A[i])>now){
            ai = A[i];
            now = min(aj - A[i], A[i]);
        }
    }
    cout << aj << " " << ai << endl;
}
