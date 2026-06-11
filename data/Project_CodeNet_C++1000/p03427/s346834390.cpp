#include <bits/stdc++.h>
using namespace std;

int main() {
    string n;
    cin >> n;
    int ans, sumn, summ, i;
    sumn = 0;
    int k = n.size();
    summ = (n.at(0) - '0') + 9 * (k - 1) - 1;
    for (i = 0; i < k; i++) sumn += (n.at(i) - '0');
    if (sumn > summ) ans = sumn;
    else ans = summ;
    cout << ans << endl;
    return 0;
}