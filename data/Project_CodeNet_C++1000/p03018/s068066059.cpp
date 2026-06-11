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


void solve() {
    str s; cin >> s;
    ll ans = 0;
    ll bcsuf = 0;
    for (int i = s.size() - 2; i >= 0; i--) {
        str sub; sub.resize(2);
        sub[0] = s[i]; sub[1] = s[i + 1];
        if (sub == "BC")
            bcsuf++;
        else if (sub == "BA" || sub == "BB" || sub == "CC" || sub == "AC")
            bcsuf = 0;
        else if (sub == "AB" || sub == "AA")
            ans += bcsuf;
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