#include<iostream>
#include<string>
using namespace std;

int cnt[3];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S;
    cin >> S;
    for (int i = 0; i < S.length(); i++) {
        cnt[S[i] - 'a']++;
    }
    if (abs(cnt[0] - cnt[1]) <= 1 && abs(cnt[1] - cnt[2]) <= 1 && abs(cnt[2] - cnt[0]) <= 1) {
        cout << "YES" << endl;
    }
    else cout << "NO" << endl;
    return 0;
}