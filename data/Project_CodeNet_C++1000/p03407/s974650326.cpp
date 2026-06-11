#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i = 0; i < (n); ++i)
int main() {
    int a, b, c;
    cin >> a >> b >> c;
    if ( c > a + b ) cout << "No" << endl;
    else                     cout << "Yes" << endl;
    return 0;
}
