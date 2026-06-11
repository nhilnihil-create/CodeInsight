#include <bits/stdc++.h>
using namespace std;
string s;
int main(void) {
    std::ios::sync_with_stdio(0);
    cin.tie(), cout.tie(0);
    int num[3];
    while(cin >> s) {
        num[0] = num[1] = num[2] = 0;
        int l = s.length();
        for(int i = 0; i < l; ++i)
            ++num[s[i] - 'a'];
        sort(num, num + 3);
        int a = 0;
        for(int i = 0; i < 3; ++i) a += num[i] != 0;
        if(a == 1) {
            if(num[2] == 1) cout << "YES" << endl;
            else cout << "NO" << endl;
        } else if(a == 2) {
            if(num[2] == 1 && num[1] == 1) cout << "YES" << endl;
            else cout << "NO" << endl;
        } else if(a == 3) {
            if(num[1] == num[0] + 1 && num[2] == num[1] + 1) cout << "NO" << endl;
            else if(num[1] <= num[0] + 1 && num[2] <= num[1] + 1) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
}