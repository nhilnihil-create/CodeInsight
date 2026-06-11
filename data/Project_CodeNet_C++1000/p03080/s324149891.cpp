#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    string s;
    cin >> N >> s;
    int cntR = 0;
    int cntB = 0;
    for(int i = 0; i < N; i++) {
        if(s[i] == 'R') {
            cntR++;
        }
        else {
            cntB++;
        }
    }
    if(cntR > cntB) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}

