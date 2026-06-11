#include <bits/stdc++.h>

using namespace std;

int main() {

    int a, b, t, r;
    cin >> a >> b >> t;

    if(a>t) {
        cout << "0" << endl;
    }else {
        r = t/a * b;       
        cout << r << endl;
    }
}