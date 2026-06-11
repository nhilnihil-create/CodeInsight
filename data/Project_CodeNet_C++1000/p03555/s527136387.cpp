#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    vector<char> C(6);

    for(int i = 0; i < 6; i++) cin >> C[i];

    for(int i = 0; i < 3; i++) {
        if(C[i] != C[5 - i]) {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
}