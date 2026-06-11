#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    string s;
    cin >> s;
    cout << 700 + 100 * count(s.begin(), s.end(), 'o') << endl;
}
