#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int a,b;
    cin >> a >> b;
    cout << (a * b % 2 == 0? "Even":"Odd") << endl;
    return 0;
}