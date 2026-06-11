#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, k;
    cin >> a >> b >> k;
    set<int> n;
    for (int i=0; i<k && a+i <= b; ++i) n.insert(a+i);
    for (int i=0; i<k && b-i >= a; ++i) n.insert(b-i);
    for (int i: n) cout << i << endl;
}