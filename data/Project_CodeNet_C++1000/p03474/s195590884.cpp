#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int A, B;
    string S;
    cin >> A >> B >> S;
    bool check = 1;

    for(int i = 0; i < A + B + 1; i++) {
        if(i != A) {
            if(S.at(i) < '0' || S.at(i) > '9') {
                check = 0;
                //cout << i << endl;
                break;
            }
            //cout << i << endl;
            
        } else {
            if(S.at(A) != '-') {
                check = 0;
                break;
            }
        }
    }

    if(check) {
    cout << "Yes" << endl;
    } else {
    cout << "No" << endl;
    }

    return 0;
}