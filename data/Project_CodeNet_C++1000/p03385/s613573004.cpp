#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    string S;
    cin >> S;

    vector<int> X(26);

    for(int i = 0; i < 3; i++) {
        X[S[i] - 'a']++;
    }

    if(X[0] == 1 && X[1] == 1 && X[2] == 1) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}