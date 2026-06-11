#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N;
string S;

int main() {
    cin >> N >> S;

    int r = 0;
    int b = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] == 'R') r++;
        else b++;
    }

    cout << ((r > b) ? "Yes" : "No") << endl;
    
    return 0;
}
