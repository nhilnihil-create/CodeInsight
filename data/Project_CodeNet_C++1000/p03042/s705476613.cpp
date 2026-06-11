#include <bits/stdc++.h>
using namespace::std;

#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef array<int, 3> tri;
typedef long double ld;

template <class T> istream& operator>>(istream& I, vector<T>& v) {for (T &e: v) I >> e; return I;}
template <class T> ostream& operator<<(ostream &O, const vector<T>& v) {for (const T &e: v) O << e << ' '; return O;}



void _main() {
        string s; cin >> s;
        int x = stoi(s.substr(0, 2));
        int y = stoi(s.substr(2));

        if (!x && !y) cout << "NA";
        else if (!x && y <= 12) cout << "YYMM";
        else if (x <= 12 && !y) cout << "MMYY";
        else if ((x > 12 && y > 12) || (!x && y > 12) || (x > 12 && !y) || (!x && !y)) cout << "NA";
        else if (x <= 12 && y <= 12 && x >= 1 && y >= 1) cout << "AMBIGUOUS";
        else if (x <= 12 && y > 12) cout << "MMYY";
        else cout << "YYMM";
}



signed main() {
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//        freopen("input.txt", "r", stdin);
        int _t = 1;
//        cin >> _t;
        while (_t--) _main();
        return 0;
}
