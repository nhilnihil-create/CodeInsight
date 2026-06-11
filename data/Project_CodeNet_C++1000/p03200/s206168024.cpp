#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    ll cnt = 0;
    ll test = 0;
    for(int i = 0; i < n; i++) {
        if (s[i]=='W'){
            cnt = cnt + (i - test);
            test++;
        }
    }
    cout << cnt << endl;

    return 0;
}