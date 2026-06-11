#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> c(9);
    for (int i = 0; i < 9; i++) cin >> c[i];
    
    int n = (c[3]+c[4]+c[5]) - (c[0]+c[1]+c[2]);
    if (n%3 != 0) {cout << "No" << endl; return 0;}
    n /= 3;

    int m = (c[6]+c[7]+c[8]) - (c[3]+c[4]+c[5]);
    if (m%3 != 0) {cout << "No" << endl; return 0;}
    m /= 3;

    if (c[3]-c[0] != n) {cout << "No" << endl; return 0;}
    if (c[6]-c[3] != m) {cout << "No" << endl; return 0;}

    if (c[4]-c[1] != n) {cout << "No" << endl; return 0;}
    if (c[7]-c[4] != m) {cout << "No" << endl; return 0;}

    if (c[5]-c[2] != n) {cout << "No" << endl; return 0;}
    if (c[8]-c[5] != m) {cout << "No" << endl; return 0;}

    cout << "Yes" << endl;
}