#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    string s;
    cin >> s;
    int mes1 = (int) (s[6] - '0');
    int mes2 = (int) (s[5] - '0');
    if (mes1 > 4 || mes2) cout << "TBD" << '\n';
    else cout << "Heisei" << '\n';
    return 0;
}