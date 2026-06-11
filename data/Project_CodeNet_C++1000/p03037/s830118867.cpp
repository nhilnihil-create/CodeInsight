#include<string>
#include<iostream>
#include<deque>
#include<cstdlib>
using namespace std;
using ulli = unsigned long long int;

int main() {
    int n, m;
    cin >> n >> m;
    int ll = 1;
    int rr = n;
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        ll = max(ll, l);
        rr = min(rr, r);
    }
    cout << ((rr - ll >= 0) ? rr - ll : -1) + 1 << endl;
    return 0;
}