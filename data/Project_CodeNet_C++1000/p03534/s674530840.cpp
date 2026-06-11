#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;
    int cnt[3] = {};
    for(int i=0; i<S.size(); ++i) cnt[(int)(S[i] - 'a')] += 1;
    if(abs(cnt[0] - cnt[1]) > 1 || abs(cnt[0] - cnt[2]) > 1 || abs(cnt[1] - cnt[2]) > 1) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
}