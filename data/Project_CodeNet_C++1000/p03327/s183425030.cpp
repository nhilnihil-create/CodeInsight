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

int n;
int main() {
    cin >> n;
    if (n >= 1000)
        cout << "ABD" << endl;
    else
        cout << "ABC" << endl;
    return 0;
}
