#include <bits/stdc++.h>
using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define ALL(x) x.begin(),x.end()
using namespace std;


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int d;
    cin >> d;
    if (d == 25) cout << "Christmas" << endl;
    else if (d == 24) cout << "Christmas Eve" << endl;
    else if (d  == 23) cout << "Christmas Eve Eve" << endl;
    else cout << "Christmas Eve Eve Eve" << endl;
    return 0;
}