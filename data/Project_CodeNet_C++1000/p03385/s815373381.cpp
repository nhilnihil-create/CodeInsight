#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
using ll = long long;


int main() {
    string s; cin >> s;
    sort(ALL(s));
    if(s == "abc") cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
