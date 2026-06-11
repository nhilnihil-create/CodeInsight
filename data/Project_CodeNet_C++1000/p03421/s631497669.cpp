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
void readVector(vector<T> & _data, L & _size, bool _shift) {
    _data.resize(_size + (ll)_shift);
    for (ll i = (ll)_shift; i < _size + (ll)_shift; i++)
        cin >> _data[i];
}

template <typename T, typename L>
void readMatrix(vector<vector<T>> & _data, L & _rows, L & _cols, bool _shiftRows, bool _shiftCols) {
    _data.resize(_rows + (ll)_shiftRows);
    for (ll i = 0; i < _rows + (ll)_shiftRows; i++)
        _data[i].resize(_cols + (ll)_shiftCols);
    for (ll i = (ll)_shiftRows; i < _rows + (ll)_shiftRows; i++)
        for (ll j = (ll)_shiftCols; j < _cols + (ll)_shiftCols; j++)
            cin >> _data[i][j];
}


//TODO: SOLUTION

void fillrem(vll & c, vb & u) {
    for (int i = u.size() - 1; i > 0; i--) {
        if (!u[i])
            c.push_back(i);
        u[i] = 1;
    }
}

void solve() {
    ll n, a, b;
    cin >> n >> a >> b;
    if (a + b - 1 > n || n > a*b) {
        cout << - 1 << endl;
        return;
    }

    vll c;
    int left = n;
    int blocs = 1;
    vb u(n + 1, false);

    while (left > 0) {
        ll k = n - a * blocs;
        if (k < 0)
            k = 0;
        repi(i, 1, a) {
            c.push_back(k + i);
            u[k + i] = 1;
            left--;
            if (i == a)
                blocs++;
            if (left + blocs - 1 == b) {
                fillrem(c, u);
                left = 0;
                break;
            }
        }

    }

    rep(i, 0, n)
    cout << c[i] << " ";
    cout << endl;
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