#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    int plan1 = n * a;
    int plan2 = b;
    if (plan1 <= plan2) cout << plan1 << endl;
    else cout << plan2 << endl;
}