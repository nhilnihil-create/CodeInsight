#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string S;
int w;

int main() {
    cin >> S >> w;

    for (int i = 0; i < S.length(); i += w) {
        cout << S[i];
    }
    cout << endl;

    return 0;
}
