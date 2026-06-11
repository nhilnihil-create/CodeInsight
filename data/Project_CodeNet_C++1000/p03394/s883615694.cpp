#include <iostream>

using namespace std;

void solve(int n) {
    if(n==3) {
        cout << "2 3 25" << endl;
        return;
    }
    cout << "2 3 4 9";
    n -= 4;
    int p24_ct = min(4999, n/2);
    n -= p24_ct * 2;
    for(int i=1; i<=p24_ct; i++) {
        cout << " " << i*6+2 << " " << i*6+4;
    }
    int p33_ct = min(2499, n/2);
    n -= p33_ct * 2;
    for(int i=1; i<=p33_ct; i++) {
        cout << " " << i*12+3 << " " << i*12+9;
    }
    while(n>0) {
        cout << " " << n--*6;
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    solve(n);
}
