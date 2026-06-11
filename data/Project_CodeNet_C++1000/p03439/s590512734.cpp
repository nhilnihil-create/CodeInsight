#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N;
    cin >> N;
    
    vector<string> S(N + 1);
    cout << 0 << endl;
    string str;
    cin >> str;
    if (str == "Vacant") return 0;
    S[0] = str;
    S[N] = str;
    int left = 0;
    int right = N;
    while (true) {
        int mid = (right + left) / 2;
        cout << mid << endl;
        cin >> str;
        if (str == "Vacant") return 0;
        S[mid] = str;
        if ((mid - left) % 2 == 0) {
            if (S[left] == S[mid]) left = mid;
            else right = mid;
        } else {
            if (S[left] != S[mid]) left = mid;
            else right = mid;
        }
    }
    return 0;
}
