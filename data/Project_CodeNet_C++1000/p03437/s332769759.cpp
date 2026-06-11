#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long X, Y;
    cin >> X >> Y;

    if (X % Y == 0) cout << -1 << '\n';
    else cout << X << '\n';

    return 0;
}