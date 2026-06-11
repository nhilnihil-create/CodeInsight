#include <bits/stdc++.h>

using namespace std;


int main() {
    int a, b, c, sum;
    cin >> a >> b >> c;
    sum = a + b + c;

    int MAX, MID, MIN;
    MAX = max(max(a, b), c);
    MIN = min(min(a, b), c);
    MID = sum - (MAX + MIN);

    cout << (MAX * 10 + MID) + MIN << endl;
}
