#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    string S;
    cin >> N >> S;

    int ans = 0;
    for (int i = 1; i < N; i++) {
        string str1 = S.substr(0, i);
        string str2 = S.substr(i);
        int cnt = 0;
        for (char ch = 'a'; ch <= 'z'; ch++) {
            bool check1 = false;
            for (int j = 0; j < (int)str1.size(); j++) {
                if (str1[j] == ch) check1 = true;
            }
            bool check2 = false;
            for (int j = 0; j < (int)str2.size(); j++) {
                if (str2[j] == ch) check2 = true;
            }
            if (check1 && check2) cnt++;
        }
        ans = max(ans, cnt);
    }

    cout << ans << endl;
}