#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
//cout << setprecision(20) << 

int main() {
    string b; cin >> b;
    for (int i = 0; i < b.size(); ++i) {
        if (b[i] == 'A') cout << 'T';
        if (b[i] == 'T') cout << 'A';
        if (b[i] == 'C') cout << 'G';
        if (b[i] == 'G') cout << 'C';
    }
    cout << endl;
}