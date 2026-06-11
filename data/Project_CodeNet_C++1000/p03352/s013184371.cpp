#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    int x;
    cin >> x;
    if(x == 1) {
        cout << 1 << endl;
        return 0;
    }

    int m = 1;

    for(int i = 2; i <= sqrt(x) + 1; i++) {
        int j = 2;
        while(pow(i, j) <= x) {
            m = max((int)pow(i, j),m);
            j++;
        }
    }

    cout << m << endl;
}