#include <bits/stdc++.h>
using namespace::std;

#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef array<int, 3> tri;
typedef long double ld;

template <class T> istream& operator>>(istream& I, vector<T>& v) {for (T &e: v) I >> e; return I;}
template <class T> ostream& operator<<(ostream &O, const vector<T>& v) {for (const T &e: v) O << e << ' '; return O;}

bool prime(int n) {
        if (n == 2) return true;
        if (n == 1 || n == 0 || n % 2 == 0) return false;
        for (int i = 3; i * i <= n; i += 2) {
                if (n % i == 0) return false;
        }
        return true;
}

void _main() {
        int n; cin >> n;
        for (int i = 1; i <= 55'555 && n; i += 5) {
                if (prime(i)) {
                        n--;
                        cout << i << ' ';
                }
        }

}



signed main() {
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//        freopen("input.txt", "r", stdin);
        int _t = 1;
//        cin >> _t;
        while (_t--) _main();
        return 0;
}
