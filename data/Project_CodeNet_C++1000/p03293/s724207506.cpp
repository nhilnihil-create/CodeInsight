#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    string s, t; cin >> s >> t;
    int sz = s.size();
    s += s;
    bool ok;
    //cout << s << endl;
    //cout << t << endl;
    for(int i = 0; i < sz; i++){
        ok = true;
        for(int j = 0; j < sz; j++){
            if(t[j] != s[i+j]){
                ok = false;
                break;
            }
        }
        if(ok) break;
    }
    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;
}