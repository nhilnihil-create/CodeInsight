#include <bits/stdc++.h>
using namespace std;

int main() {
    string n, m;
    cin >> n;
    int ans, sumn, summ, i;
    long long power = 1;
    sumn = 0; summ = 0;
    int digit = n.size();
    if (digit == 1) ans = stoi(n);
    else {
        for (i = 0; i < digit - 1; i++) power *= 10;
        m = to_string((n.at(0) - '0') * power -1);
        for (i = 0; i < m.size(); i++) summ += (m.at(i) - '0');
        for (i = 0; i < digit; i++) sumn += (n.at(i) - '0');
        if (sumn > summ) ans = sumn;
        else ans = summ;
    }
    cout << ans << endl;
    return 0;
}