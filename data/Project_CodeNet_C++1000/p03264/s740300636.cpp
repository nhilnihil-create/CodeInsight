/**
 *    author:  tootal    
 *    created: 2020/04/11 15:45:45
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int k;
    cin >> k;
    cout << ((k * k - (k & 1)) >> 2) << endl;
    return 0;
}