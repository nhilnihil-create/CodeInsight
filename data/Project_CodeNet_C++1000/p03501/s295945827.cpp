#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a, b;
    int x;

    cin >> n >> a >> b;

    // プラン1での駐車料金
    x = n * a;
    
    if (x > b) {
        cout << b << endl;
    }
    else {
        cout << x << endl;
    }
}