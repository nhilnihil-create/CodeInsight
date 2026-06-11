#include <bits/stdc++.h>
using namespace std;

int main() {
    int t[2],b[2];
    cin >> t[0] >> t[1] >> b[0] >> b[1];

    sort(t,t+2);
    sort(b,b+2);

    cout << t[0]+b[0];
    return 0;
}