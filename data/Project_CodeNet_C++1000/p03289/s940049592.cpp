#include<bits/stdc++.h>
using namespace std;

int main(){
    string S;
    cin >> S;
    if(S[0] != 'A') {
        cout << "WA" << endl;
        return 0;
    }
    int cnt = 0;
    for(int i = 2; i < S.size()-1; i++) {
        if(S[i] == 'C') {
            cnt++;
        }
    }
    if(cnt != 1) {
        cout << "WA" << endl;
        return 0;
    }
    for(int i = 1; i < S.size(); i++) {
        if(S[i] == 'C') {
            continue;
        }
        else if(S[i] >= 'a' && S[i] <= 'z') {
            continue;
        }
        else {
            cout << "WA" << endl;
            return 0;
        }
    }
    cout  << "AC" << endl;
}

