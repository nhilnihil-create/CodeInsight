#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;
    
    vector<string> s(n);
    int cnt = 0; 
    rep(i, n){
        cin >> s[i];
        if(s[i] == "Y"){
            cout << "Four" << endl;
            break;
        }
        cnt++;
    }
    if(cnt == n) cout << "Three" << endl;
    
}