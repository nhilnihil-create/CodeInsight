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

int main() {
    string s;
    cin >> s;
    string ostr = "Heisei";
    string m = s.substr(5,2);
    int mm = stoi(m);
    if (mm > 4)
        cout << "TBD" << endl;
    else
        cout << ostr << endl;

    return 0;
}
