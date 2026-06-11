#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define all(a) (a).begin(), (a).end()


int main() {
    int D;
    cin >> D;
    string s;
    if(D == 25)s = "Christmas";
    else if(D == 24) s = "Christmas Eve";
    else if(D==23) s = "Christmas Eve Eve";
    else s = "Christmas Eve Eve Eve";
    cout << s << endl;
}
