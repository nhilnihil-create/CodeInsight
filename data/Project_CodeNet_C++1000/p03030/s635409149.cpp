#include <iostream>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define Rep(i, s, n) for (int i = (int)s; i < (int)n; i++)

int main() {
    cin.tie(0);
   	ios::sync_with_stdio(false);

    struct Rest {
        int num;
        string name;
        int point;

        bool operator<( const Rest& right ) const {
            return name == right.name ? point > right.point : name < right.name;
        }
    };

    int n;
    cin >> n;
    Rest r[n];
    rep(i, n) {
        string s;
        int p;
        cin >> s >> p;
        r[i].num = i;
        r[i].name = s;
        r[i].point = p;
    }

    sort(r, r + n);
    rep(i, n) {
        cout << r[i].num + 1 << endl;
    }
}