#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
 
int main() {
    long a, b, k, idx = 0;
    cin >> a >> b >> k;

    long c = min(a + k - 1, b);
 
    for(int i = a; i <= c; i++)
        cout << i << endl;
 
    if(c == b)
        return 0;
 
    long d = max(c + 1, b - (k - 1));
    for(int i = d; i <= b; i++)
        cout << i << endl;
}