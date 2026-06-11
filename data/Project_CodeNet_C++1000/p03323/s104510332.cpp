#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;
#define DEBUG freopen("in.txt", "r", stdin);

struct fastio {
    fastio() {
        ios::sync_with_stdio(false);
        cout << setprecision(10) << fixed;
        cin.tie(0);
    }
};

fastio _fast_io;

int a, b;
int main() {
    cin >> a >> b;
    if (a <= 8 && b <= 8)
        cout << "Yay!" << endl;
    else
        cout << ":(" << endl;
    return 0;
}
