#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

int main() {
    int a, b;
    string s;
    cin >> a >> b >> s;
    if(s.size()!=a+b+1) {cout << "No" << endl; return 0;}
    if(s[a]!='-') {cout << "No" << endl; return 0;}
    rep(i,s.size()){
        if(i==a) continue;
        bool ok = false;
        if(s[i]>='0' && s[i]<='9') ok = true;
        if(!ok) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}