#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    string S;
    cin >> S;
    bool check = 1;
    
    if(S.at(0) != 'A') {
        check = 0;
    }
    int count = 0;
    int Ci = 0;
    for(int i = 2; i < S.size() - 1; i++) {
        if(S.at(i) == 'C') {
            count++;
            Ci = i;
        }
    }
    if(count != 1) {
        check = 0;
    }
    if(check) {
        for(int i = 0; i < S.size(); i++) {
            if(!(S.at(i) >= 'a' && S.at(i) <= 'z') && ((i != 0 && i != Ci))) {
                check = 0;
            }
            if(i == 0 || i == Ci) {
                //continue;
            }
        }
    }
    if(check) {
    cout << "AC" << endl;
    } else {
    cout << "WA" << endl;
    }


    return 0;
}