#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
    ll A, B, X;
    cin >> A >> B >> X; 

    if (A <= X && A + B >= X) cout << "YES" << endl;
    else cout << "NO" << endl;
}


