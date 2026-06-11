#include <bits/stdc++.h>

using namespace std;

int main(){

    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt", "r", stdin);

    int a, b, c;

    cin >> a >> b >> c;

    if((a <= c  && c <= b) || (a >= c && c >= b))
        cout << "Yes";
    else
        cout << "No";
    return 0;
}
