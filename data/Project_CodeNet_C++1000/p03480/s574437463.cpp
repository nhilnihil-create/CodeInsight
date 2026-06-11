#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    string S;
    cin >> S;

    vector<int> x;

    int c = 1;
    char a = S[0];

    for(int i = 1; i < S.length(); i++) {
        if(a == S[i]) c++;
        else {
            x.push_back(c);
            a = S[i];
            c = 1;
        }
    }

    x.push_back(c);

    if(x.size() == 1) {
        cout << S.length() << endl;
    } else if(x.size() == 2) {
        cout << max(x[0], x[1]) << endl;
    } else {
        int b = 10000000;
        int z = 0;
        for(int i = 0; i < x.size() - 1; i++) {
            b = min(b, max(z + x[i], (int)S.length() - (z + x[i])));
            z += x[i];
        }
        cout << b << endl;
    }
}