#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int64_t a,b,n;
    cin >> a >> b;
    n = b-a;
    cout << n*(n+1)/2-b << endl;
}