#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <sstream>
#include <cmath>
#include <math.h>
#include <string>
using namespace std;
typedef long long ll;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, z = 0;
    string s[102] = {}, t[102] = {};
    cin >> n;
    for (int i = 0; i < n; i++) cin >> s[i];
    cin >> m;
    for (int i = 0; i < m; i++) cin >> t[i];
    for (int i = 0; i < n; i++) {
        int c = 0;
        int d = 0;
        for (int j = 0; j < n; j++) {
            if (s[i] == s[j]) c++;
        }
        for (int j = 0; j < m; j++) {
            if (s[i] == t[j]) d++;
        }
        z = max( z , c - d );
    }
    cout << z;
}
