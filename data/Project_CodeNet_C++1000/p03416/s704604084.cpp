#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    int A, B; cin >> A >> B;
    int ans = 0;
    for (int i = A; i <= B; i++) {
        string S_reverse = to_string(i);
        reverse(S_reverse.begin(), S_reverse.end());
        string S = to_string(i);
        if (S == S_reverse) {
            ans++;
        }
    }
    cout << ans << endl;
}
