#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n;
    cin >> n;
    vector<char> s(n);
    for (int i=0; i<n; i++) cin >> s[i];
    int y = 0;
    for (auto x : s){
        if (x == 'Y') y++;
    }
    cout << (y == 0 ? "Three" : "Four") << endl;
    return 0;
}