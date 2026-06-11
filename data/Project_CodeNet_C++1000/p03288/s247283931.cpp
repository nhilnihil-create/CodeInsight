#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9 + 7;
const ll longinf = 1LL << 60;
const ll mod = 1e9 + 7;

int main() {
    int R;
    cin >> R;
    if(R < 1200)
        cout << "ABC";
    else if(R < 2800)
        cout << "ARC";
    else
        cout << "AGC";

    return 0;
}