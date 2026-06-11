#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
    string s;
    cin >> s;

    int toppingCnt = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'o') ++toppingCnt;
    }

    cout << 700 + toppingCnt * 100 << endl;

}
