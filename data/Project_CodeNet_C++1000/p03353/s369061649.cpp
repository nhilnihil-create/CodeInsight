#include <bits/stdc++.h>

using namespace std;

int main (void) {
    string s;
    int k;
    cin >> s >> k;

    vector<string> subs;
    for ( int si = 0; si < s.size(); si++ ) {
        for ( int len = 1; len <= k; len++ )
            subs.push_back(s.substr(si, len));
    }

    sort(subs.begin(), subs.end());

    auto n = unique(subs.begin(), subs.end());
    subs.erase(n, subs.end());

    cout << subs.at(k-1) << endl;
    return 0;
}
