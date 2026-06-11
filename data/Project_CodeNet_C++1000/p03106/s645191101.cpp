#include <iostream>
using namespace std;

int main() {
    int a, b, k;
    cin >> a >> b >> k;
    int min;
    if (a > b) min = b;
    else min = a;
    if (min == 1) {
        cout << 1 << endl;
        return 0;
    }
    int c[100001] ;
    int cnt = 0;
    for (int i = min; i > 0; i--) {
        if (a % i == 0 && b % i == 0) cnt++;
        if (cnt == k) {
            cout << i << endl;
            return 0;
        }
    }

    // for (int i = 0; i < cnt; i++) cout << c[i] << endl;
    
    // cout << c[k-1] << endl;
    // return 0;
}