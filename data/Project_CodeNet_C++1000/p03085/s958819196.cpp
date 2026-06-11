#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    char b;
    cin >> b;
    string ans;
    if (b == 'A') ans = 'T';
    if (b == 'T') ans = 'A';
    if (b == 'G') ans = 'C';
    if (b == 'C') ans = 'G';
    cout << ans << endl;
    return 0;
}