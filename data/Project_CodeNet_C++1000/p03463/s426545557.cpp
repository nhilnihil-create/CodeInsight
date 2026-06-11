#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n, a, b;
    cin >> n >> a >> b;
    cout << ((a - b) % 2 == 0 ? "Alice\n" : "Borys\n");
    return 0;
}