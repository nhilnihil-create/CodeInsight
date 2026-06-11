#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

#define rep(i,n) for (int i = 0; i < (n); ++i)

const ll MOD = 1000000007;

int main() {
    int n;
    cin >> n;

    if ( n == 1) cout << "Hello World" << endl;
    else if ( n == 2 ) {
        int a, b;
        cin >> a >> b;
        cout << a + b << endl;
    }

    return 0;
}