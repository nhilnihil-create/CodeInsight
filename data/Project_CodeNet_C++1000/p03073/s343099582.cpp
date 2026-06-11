#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    string s;
    int a = 0, b = 0;
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        if (i % 2) {
            if (s[i] == '0') a++;
            else b++;
        } else {
            if (s[i] == '1') a++;
            else b++;
        }
    }
    cout << min(a, b);
}
