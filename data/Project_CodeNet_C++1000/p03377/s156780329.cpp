#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B, X;
    cin >> A >> B >> X;
    if (A>X) cout <<"NO\n";
    else if (X-A<=B) cout << "YES\n";
    else cout << "NO\n";
}