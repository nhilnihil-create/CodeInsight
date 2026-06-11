#include<iostream>
using namespace std;

int main() {
    string S; cin >> S;
    int ans = 0;
    int temp = 0;
    for (int i = 0; i < S.size(); i++) {
        if (S[i] == 'A' || S[i] == 'T' || S[i] == 'G' || S[i] == 'C') {
            temp++;
        } else {
            ans = max(ans, temp);
            temp = 0;
        }
    }
    ans = max(ans, temp);
    cout << ans << endl;
}
