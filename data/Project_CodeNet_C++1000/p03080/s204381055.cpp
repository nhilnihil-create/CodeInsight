#include <bits/stdc++.h>
using namespace std;

#define watch(x) cerr << (#x) << ": " << (x) << endl
#define int long long



int32_t main() {

    int n; cin >> n;
    string s; cin >> s;
    int red = 0, blue = 0;
    for(char c : s) {
        if(c == 'R') red++;
        else if(c == 'B') blue++;
    }
    if(red > blue) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}
