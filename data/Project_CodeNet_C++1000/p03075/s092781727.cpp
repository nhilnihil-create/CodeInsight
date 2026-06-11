
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int a, b, c, d, e, k;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> a >> b >> c >> d >> e >> k;
    if (e - a > k)
        cout << ":(" << endl;
    else
        cout << "Yay!" << endl;

    return 0;
}

