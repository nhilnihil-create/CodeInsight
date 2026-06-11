#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;

int main(){

    int a, b;
    cin >> a >> b;
    string s;
    cin >> s;

    bool ok = true;
    if(a+b+1 != (int)s.size()) ok = false;
    else{
        if(s[a] != '-') ok = false;
        else{
            for(int i = 0; i < a; i++){
                if((s[i] < '0') || ('9' < s[i])) ok = false;
            }
            for(int i = a+1; i < (int)s.size()-1; i++){
                if((s[i] < '0') || ('9' < s[i])) ok = false;
            }
        }
    }

    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    return 0;
}