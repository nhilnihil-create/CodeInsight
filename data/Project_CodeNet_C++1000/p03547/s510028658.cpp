#include <bits/stdc++.h>

#define rep(l, r) for (int i = (l); i < (r); i++)

typedef long long ll;
 
using namespace std;

int main() {
    char x, y;
    cin >> x >> y;

    cout << (x == y ? '=' : x < y ? '<' : '>') << endl;

    return 0;
}
