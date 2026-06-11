#include <bits/stdc++.h>
using namespace std;

int alphabet[('z' - 'a' + 1)];

int main() {
    string S;
    cin >> S;
    if(S.size() < 26) {
        for(auto &p : S) ++alphabet[p - 'a'];
        for(int i = 0; i < 'z' - 'a' + 1; ++i) {
            if(!alphabet[i]) {
                cout << (S + (char)(i + 'a')) << endl;
                return 0;
            }
        }
    }

    int i = S.size()-1;
    while(i-1 >= 0 && S[i-1] > S[i]) --i;
    //cout << i << endl;
    if(i == 0) {
        cout << -1 << endl; 
    }
    else {
        char ch = 'z';
        for(int j = S.size()-1; j >= i; --j) {
            if(S[j] > S[i-1]) {
                ch = min(ch, S[j]);
            }
        }
        cout << (S.substr(0, i-1) + ch) << endl;
    }
    return 0;
}