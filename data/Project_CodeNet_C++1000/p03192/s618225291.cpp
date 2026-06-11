#include<bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;
    int ans = 0;
    if(S[0] == '2') {
        ans++;
    } 
    if(S[1] == '2') {
        ans++;
    }
    if(S[2] == '2') {
        ans++;
    }
    if(S[3] == '2') {
        ans++;
    }
    cout << ans << endl;
}

