#include <bits/stdc++.h>
using namespace std;
int main() {
    int a,b,x; cin >> a >> b >> x;
    bool ok = true;
    if(a > x) ok = false;
    else if(a+b < x) ok = false;
    if(ok) cout << "YES" << endl;
    else cout << "NO" << endl;
}