#include<bits/stdc++.h>
using namespace std;

int main(){
    string S;
    cin >> S;
    int cnt = 0;
    for(int i = 0; i < S.size(); i++) {
        if(S[i] == 'o') {
            cnt++;
        }
    }
    if(cnt+(15-S.size()) >= 8) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
} 
