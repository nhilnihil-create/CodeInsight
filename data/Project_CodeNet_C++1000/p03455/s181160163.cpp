#include<bits/stdc++.h>
using namespace std;

int main() {
    int a, b; cin >> a >> b; a *= b;
    if (a & 1) cout << "Odd" << endl;
    else cout << "Even" << endl;
    return 0;
}