#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    string S; cin >> S;
    int t = 0;
    for (char c : S) if (c == '.') t++;
    int ans = t; 
    for (char c : S) {
        if (c == '.') t--;
        if (c == '#') t++;
        ans = min(ans, t);
    }
    cout << ans << endl;
}