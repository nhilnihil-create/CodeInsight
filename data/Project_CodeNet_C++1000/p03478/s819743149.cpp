#include<iostream>
using namespace std;

int main() {
    int N, A, B; cin >> N >> A >> B;
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        int sum = 0;
        string s = to_string(i);
        for (int j = 0; j < s.size(); j++) {
            sum += s[j] - '0';
        }
        if (sum >= A && sum <= B) {
            ans += i;
        }
    }
    cout << ans << endl;
}
