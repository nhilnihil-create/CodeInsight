#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

#define rep(i,n) for(int i = 0; i < (n); ++i)

int main() {
    int a, b;
    cin >> a >> b;
    if ( a + b == 15 ) {
        cout << "+" << endl;
    }
    else if ( a * b == 15 ) {
        cout << "*" << endl;
    }
    else {
        cout << "x" << endl;
    }
    return 0;
}
