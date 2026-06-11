#include <bits/stdc++.h>

#define tc(t) int t; cin>>t; while(t--)
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s; cin >> s;
    int aa = 0;
    int bb = 0;
    int cc = 0;
    for (int i = 0; i < s.length(); ++i) {
        if(s[i] == 'a') aa++;
        else if (s[i] == 'b') bb++;
        else cc++;
    }
    if( aa == 1 && bb == 1 && cc == 1){
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }



}




