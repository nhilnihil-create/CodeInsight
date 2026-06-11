#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    string S; cin >> S;
    int ans = 1000;
    for (int i = 0; i < S.size() - 2; i++) {
        int picked_number = stoi(S.substr(i, 3));
        int diff = max(picked_number - 753, 753 - picked_number);
        ans = min(ans, diff);
    }
    cout << ans << endl;
}
