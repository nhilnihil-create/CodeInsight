#include <bits/stdc++.h>
using namespace std;

int main () {
    int n,a,b; cin >> n >> a >> b;
    cout << min(a,b) << ' ' << (n-a-b >= 0 ? 0 : a+b-n) << endl;
}

