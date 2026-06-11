#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> num(4);
    for (int i = 3; i >= 0; i--) {
        num.at(i) = N % 10;
        N /= 10;
    }
    for (int bit = 0; bit < (1<<3); bit++) {
        string ans;
        int sum = num.at(0);
        ans.push_back('0' + num.at(0));
        for (int i = 0; i < 3; i++) {
            if (bit & (1<<i)) {
                sum += num.at(i + 1);
                ans.push_back('+');
                ans.push_back('0' + num.at(i + 1));
            }
            else {
                sum -= num.at(i + 1);
                ans.push_back('-');
                ans.push_back('0' + num.at(i + 1));
            }
        }
        if (sum == 7) {
            ans += "=7";
            cout << ans << endl;
            return 0;
        }
    }
}