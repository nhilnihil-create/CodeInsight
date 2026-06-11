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

const int N = 1e5 + 5;
int n, m, k, ans;

int main() {
    cin >> n;
    // Write a program that prints Christmas if
    //D
    //=
    //25
    //, Christmas Eve if
    //D
    //=
    //24
    //, Christmas Eve Eve if
    //D
    //=
    //23
    // and Christmas Eve Eve Eve if
    //D
    //=
    //22
    //.
    if (n == 25)
        cout << "Christmas" << endl;
    else if (n == 24)
        cout << "Christmas Eve" << endl;
    else if (n == 23)
        cout << "Christmas Eve Eve" << endl;
    else if (n == 22)
        cout << "Christmas Eve Eve Eve" << endl;
    return 0;
}
