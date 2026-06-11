#include <bits/stdc++.h>
using namespace std;
string s;
int main(void) {
    std::ios::sync_with_stdio(0);
    cin.tie(), cout.tie(0);
    int num[3];
    while(cin >> s) {
        num[0] = num[1] = num[2] = 0;
        for(int i = 0; s[i]; ++i)
            ++num[s[i] - 'a'];
        sort(num, num + 3);
        int a = num[2] - num[0];
        cout << (a <= 1 ? "YES" : "NO") << endl;
    }
}
