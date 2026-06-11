#include <bits/stdc++.h>

#define ll long long
#define str string
#define pii pair<int, int>
#define pll pair<ll, ll>
#define fi first
#define se second

#define vc vector<char>
#define vvc vector<vc>
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vi>
#define vvll vector<vll>
#define vvvll vector<vvll>
#define vs vector<str>
#define vvs vector<vs>
#define vpii vector<pii>
#define vvpii vector<vpii>
#define vpll vector<pll>
#define vvpll vector<vpll>
#define vb vector<bool>
#define vvb vector<vb>
#define rep(i, a, b) for (int i = (a); i < int(b); i++)
#define repi(i, a, b) for (int i = (a); i <= int(b); i++)


using namespace std;
ll INF = LONG_LONG_MAX;
ll mod = 1000000000 + 7;

template <typename T, typename L>
void read(vector<T> & _data, L & _size, bool _shift) {
    _data.resize(_size + (ll)_shift);
    for (ll i = (ll)_shift; i < _size + (ll)_shift; i++)
        cin >> _data[i];
}

template <typename T, typename L>
void read(vector<vector<T>> & _data, L & _rows, L & _cols, bool _shiftRows, bool _shiftCols) {
    _data.resize(_rows + (ll)_shiftRows);
    for (ll i = 0; i < _rows + (ll)_shiftRows; i++)
        _data[i].resize(_cols + (ll)_shiftCols);
    for (ll i = (ll)_shiftRows; i < _rows + (ll)_shiftRows; i++)
        for (ll j = (ll)_shiftCols; j < _cols + (ll)_shiftCols; j++)
            cin >> _data[i][j];
}

template <typename T>
void write(vector<T> & _data, bool _shift) {
    for (ll i = (ll)_shift; i < _data.size(); i++)
        cout << _data[i] << " ";
    cout << endl;
}


//TODO: SOLUTION

ll n, c, m;
vll x, v, seg;

void mktree() {
    m = 1;
    while (m < n)
        m *= 2;
    seg.clear();
    seg.resize(2 * m, 0);
    ll sum = 0;
    rep(i, 0, n) {
        sum += v[i];
        seg[m + i] = sum - x[i];
    }

    for (int i = m - 1; i > 0; i--) {
        seg[i] = max(seg[2 * i], seg[2 * i + 1]);
    }
}

ll get(int l, int r) {
    l += m;
    r += m;
    ll ans = 0;
    while (l <= r) {
        if (l&1)
            ans = max(ans, seg[l++]);
        if (!(r&1))
            ans = max(ans, seg[r--]);
        l /= 2;
        r /= 2;
    }
    return ans;
}

void solve() {
    cin >> n >> c;
    x.resize(n);
    v.resize(n);

    rep(i, 0, n) {
        cin >> x[i] >> v[i];
    }

    mktree();

    ll sum = 0;
    ll ans = get(0, n - 1);
    for (int i = n - 1; i >= 0; i--) {
        sum += v[i];
        ans = max(ans, sum - 2 * (c - x[i]) + get(0, i - 1));
    }

    reverse(x.begin(), x.end());
    reverse(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        x[i] = c - x[i];
    }

    mktree();

    ans = max(ans, get(0, n - 1));
    sum = 0;
    for (int i = n - 1; i >= 0; i--) {
        sum += v[i];
        ans = max(ans, sum - 2 * (c - x[i]) + get(0, i - 1));
    }

    cout << ans << endl;
}


int main() {

    // TODO: Set value of this variable manually
    bool _multipleTestCases = false;

    if (_multipleTestCases) {
        ll t; cin >> t;
        while (t--)
            solve();
    }
    else {
        solve();
    }

    return 0;
}