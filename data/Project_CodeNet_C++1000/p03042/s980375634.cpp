#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int a,b;
    cin >> a;
    b = a % 100;
    a /= 100;
    if(a> 12 || a == 0) {
        if(b > 12 || b == 0){
            cout << "NA\n";
        } else {
            cout << "YYMM\n";
        }
    } else {
        if(b > 12 || b == 0){
            cout << "MMYY\n";
        } else {
            cout << "AMBIGUOUS\n";
        }
    }
    return 0;
}
