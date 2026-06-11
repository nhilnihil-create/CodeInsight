#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

int main() {
    string s;
    cin >> s;
    if(s.front()!='A') {cout << "WA" << endl; return 0;}
    bool ok = true;
    int cnt = 0;
    if(s[1] >= 'A' && s[1] <= 'Z') ok = false;
    for(int i = 2; i <= s.size()-2; ++i) {
        if(s[i]=='C') {cnt++; continue;}
        if(s[i] >= 'A' && s[i] <= 'Z') ok = false; 
    }
    if(s[s.size()-1] >= 'A' && s[s.size()-1] <= 'Z') ok = false;
    if(cnt!=1 || !ok) {cout << "WA" << endl; return 0;}
    cout << "AC" << endl;
    return 0;
}