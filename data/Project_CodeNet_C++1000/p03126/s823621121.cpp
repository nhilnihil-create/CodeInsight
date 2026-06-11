#include <bits/stdc++.h>
using namespace std;
#define ll long long int


int main() {
    int n, m;
    cin >> n >> m;
    bitset<31> b;
    b.flip();
    while (n--) {
        int k;
        cin >> k;
        bitset<31> bTry;
        for (int i = 0; i<= k - 1; i++) {
            int a;
            cin >> a;
            bTry[a] = 1;
        }

        b = (b&bTry);
        //cout << b << '\n';
    }
    cout << b.count() << '\n';
    return 0;
}