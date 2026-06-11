#include <bits/stdc++.h>
using namespace std;

int output1(long a, long b, long k) {
    for (int i = a; i < a + k; i++) {
        cout << i << endl;
    }
    for (int i = b - k + 1; i <= b; i++) {
        cout << i << endl;
    }
    return 0;
}

int output2(long a, long b) {
    for (int i = a; i <= b; i++) {
        cout << i << endl;
    }
    return 0;
}


int main() {
    long a, b, k;
    cin >> a >> b >> k;
    
    if ((b - a + 1) > (k * 2)) {
        output1(a,b,k);
    } else {
        output2(a,b);
    }
    
}
