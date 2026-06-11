#include <bits/stdc++.h>

#define rep(l, r) for (int i = (l); i < (r); i++)

typedef long long ll;
 
using namespace std;

int main() {
    int y, m, d;
    scanf("%d/%d/%d", &y, &m, &d);

    cout << (y <= 2019 && m <= 4 && d <= 30 ? "Heisei" : "TBD") << endl;

    return 0;
}
