#include <bits/stdc++.h>
#define rep(i,n) for (int i =0; i < (n); ++i)
using namespace std;

int main() {
        int n, k;
        string s;
        cin >> n >> k;
        cin >> s;
        k--;

        if (s[k] >= 'A' && s[k] <= 'Z') {
                s[k] = s[k] += 'a' - 'A';
        }
        cout << s << endl;
        return 0;
}
