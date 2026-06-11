#include <bits/stdc++.h>
using namespace std;

vector < char > from = {'3', '5', '7'};

int64_t rec (string &n, vector < char > &a, int j, map < char, int > &saw) {
    for (int i = 0; i < j; ++i) {
        if (n[i] > a[i])
            break;
        else if (a[i] > n[i])
            return int64_t(0);
    }
    if (j == int(a.size()) && saw['3'] && saw['5'] && saw['7'])
        return int64_t(1);
    else if (j == int(a.size()))
        return int64_t(0);
    else {
        int64_t res = 0;
        if (j) {
            for (char c: from) {
                a[j] = c;
                ++saw[c];
                res += rec(n, a, j + 1, saw);
                --saw[c];
                a[j] = '0';
            }
        }
        else {
            for (int i = 0; i < int(n.size()) - 2; ++i) {
                for (char c: from) {
                    a[i] = c;
                    ++saw[c];
                    res += rec(n, a, i + 1, saw);
                    --saw[c];
                    a[i] = '0';
                }
            }
        }
        return res;
    }
}

signed main () {
    vector < int64_t > three(10);
    vector < int64_t > fact(10);
    three[0] = fact[0] = 1;
    for (int64_t i = 1; i < 10; ++i) {
        three[i] = three[i - 1] * 3;
        fact[i] = fact[i - 1] * i;
    }
    
    string n;
    cin >> n;
    vector < char > a(int(n.size()), '0');
    map < char, int > saw;
    cout << rec(n, a, 0, saw) << '\n';
}
