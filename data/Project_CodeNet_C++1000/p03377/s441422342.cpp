#include <bits/stdc++.h>
using namespace std;

int main(){

    int a, b, x, tot;
    cin >> a >> b >> x;
    tot = a + b;

    if(x - a >= 0 && x - a + a <= tot) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}