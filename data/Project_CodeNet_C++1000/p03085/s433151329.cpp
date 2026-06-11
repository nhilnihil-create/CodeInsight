#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;

struct fastio {
    fastio() {
        ios::sync_with_stdio(false);
        cout << setprecision(10) << fixed;
        cin.tie(0);
    }
};

fastio _fast_io;

char c;
int main() {
    cin >> c;
    if (c == 'A')
        cout << 'T' << endl;
    else if (c == 'T')
        cout << 'A' << endl;
    else if (c == 'C')
        cout << 'G' << endl;
    else
        cout << 'C' << endl;
    return 0;
}
