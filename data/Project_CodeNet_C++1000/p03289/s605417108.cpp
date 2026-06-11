#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;

int main(){

    string s;
    cin >> s;

    bool ok = true;

    if(s[0] != 'A'){
        cout << "WA" << endl;
        return 0;
    }

    int c_cnt = 0;
    for(int i = 2; i < (int)s.size()-1; i++){
        if(s[i] == 'C') c_cnt++;
    }
    if(c_cnt != 1){
        cout << "WA" << endl;
        return 0;
    }

    for(int i = 1; i < (int)s.size(); i++){
        if(isupper(s[i])){
            if(s[i] != 'C') ok = false;
        }
    }
    if(ok) cout << "AC" << endl;
    else cout << "WA" << endl;
    
    return 0;
}