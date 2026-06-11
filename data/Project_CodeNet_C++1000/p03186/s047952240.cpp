#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int a, b, c;
    cin >> a >> b >> c;

    long long int ans = b;
    ans += min(c, a + b + 1);
    cout << ans << endl;
    return 0;
}