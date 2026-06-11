#include <bits/stdc++.h>
using namespace std;

int main () {
    int a, b; cin >> a >> b;

    int t;
    if (a < b){
        t = a;
        a = b;
        b = t;
    }

    if (a - b <= (16 - (2 * b)) / 2)
        cout << "Yay!";
    else 
        cout << ":(";
}