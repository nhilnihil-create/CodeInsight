#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
    string s;
    cin >> s;
    sort(s.begin(),s.end());
    if (s == "abc") {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
