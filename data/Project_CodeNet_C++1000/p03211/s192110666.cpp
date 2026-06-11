#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repm(i, m, n) for (int i = m; i < (n); i++)
#define eps (1e-7)
#define inf (1e9)
#define pi (acos(-1))
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    string str;
    cin >> str;

    int _min = inf;
    rep(i, str.size() - 2)
    {
        string s = str.substr(i, 3);
        int si = stoi(s);
        _min = min(_min, abs(si - 753));
    }

    cout << _min << endl;

    return 0;
}