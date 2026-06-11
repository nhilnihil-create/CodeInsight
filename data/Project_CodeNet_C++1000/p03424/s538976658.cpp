#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); ++i)
double const PI = 3.1415926535897932384626433;
using P = pair<int, int>;

int main() {
    int n;
    cin >> n;
    set<char> a;
    rep(i, n) {
        char tmp;
        cin >> tmp;
        a.insert(tmp);
    }
    if (a.size() == 4)
        cout << "Four" << endl;
    else
        cout << "Three" << endl;
    return 0;
}