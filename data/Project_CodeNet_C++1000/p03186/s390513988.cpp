#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int a, b, c, res =0;
    cin >> a >> b >>c;
    res =a + b + 1;
    if(res >= c)
      cout << b + c;
    else
        cout << b + res;

}