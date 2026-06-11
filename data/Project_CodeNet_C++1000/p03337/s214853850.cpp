#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main(){
    ll a, b;
    cin >> a >> b;
    cout << max(a + b, max(a - b, a * b));
    return 0;
}
