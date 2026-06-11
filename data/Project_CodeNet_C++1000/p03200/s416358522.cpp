#include <bits/stdc++.h>
using namespace std;
typedef long long Int;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    string s; cin >> s;
    int ans = 0;
    Int sum_w = 0;
    Int sum = 0;
    for(int i = 0; i < s.size(); i++) {
        if (s[i] == 'W') {
            sum_w++;
            sum += (Int)i;
        }
    }
    cout << sum - (sum_w*(sum_w-1)/2) << endl;
}