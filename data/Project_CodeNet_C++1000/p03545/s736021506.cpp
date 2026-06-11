/**
*    created: 24.06.2020 01:43:17
**/
#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define pcnt(bit) __builtin_popcount(bit)
#define mod 1000000007
#define pi acos(-1.0)
using namespace std;

int ctoi(char c) {
	
}

signed main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    string s;
    cin >> s;
    auto ctoi = [&] (char c) {
        if (c >= '0' && c <= '9') return c - '0';
	    return -1;
    };
    int a = ctoi(s[0]);
    int b = ctoi(s[1]);
    int c = ctoi(s[2]);
    int d = ctoi(s[3]);

    for (int bit = 0; bit < (1 << 3); bit++) {
        int sum = a;
        string str = to_string(a);
        if ((bit >> 0) & 1) {
            sum += b;
            str.insert(1,"+");
        }
        else {
            sum -= b;
            str.insert(1,"-");
        }
        str.insert(2,to_string(b));
        if ((bit >> 1) & 1) {
            sum += c;
            str.insert(3,"+");
        }
        else {
            sum -= c;
            str.insert(3,"-");
        }
        str.insert(4,to_string(c));
        if ((bit >> 2) & 1) {
            sum += d;
            str.insert(5,"+");
        }
        else {
            sum -= d;
            str.insert(5,"-");
        }
        str.insert(6,to_string(d));
        if (sum != 7) continue;
        str.insert(7,"=7");
        cout << str << endl;
        return 0;
    }
    return 0;
}