#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
   int A,B,C;
   cin >> A >> B >> C;

    if(A * C < B) cout << C;
    else cout << B / A;
    return 0;
}