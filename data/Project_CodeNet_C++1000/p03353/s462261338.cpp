#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;
const ll inf = 1LL<<60;
const double eps = 1e-9;

typedef pair<ll, ll> P;

int main()
{
    string s;
    int k;
    cin >> s >> k;
    set<string> tmp;

    for (int i = 1; i <= int(s.size()); i++) {
        for (int j = 0; j < int(s.size()) && i <= k; j++) {
            if (i+j > int(s.size())) break;
            tmp.insert(s.substr(j, i));
        }
    }
    int i = 1;
    for (auto x: tmp) {
        if (i == k) cout << x << endl;
        i++;
    }

    return 0;
}

