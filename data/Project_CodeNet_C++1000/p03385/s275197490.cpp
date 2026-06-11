#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
#define in insert

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    set<char> se;
    for(int i = 0; i < s.size(); i++) {
        se.in(s[i]);
    }
    if(se.size() == 3) {
        cout << "Yes";
    } else {
        cout << "No";
    }
}
