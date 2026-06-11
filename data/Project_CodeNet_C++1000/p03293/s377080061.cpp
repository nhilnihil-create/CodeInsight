#include <bits/stdc++.h>
using namespace std;
#define int long long

string rotate(string s){
    string ans = "";
    for(int i=1; i<s.size(); i++){
        ans += s[i];
    }
    return ans + s[0];
}

signed main(){
    // cout << fixed << setprecision(10) << flush;

    string s, t;
    cin >> s >> t;
    for(int i=0; i<=s.size(); i++){
        if(s == t){
            cout << "Yes" << endl;
            return 0;
        }
        else{
            s = rotate(s);
        }
    }    

    cout << "No" << endl;
    return 0;
}