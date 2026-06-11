#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    string s;
    cin>>s;
    string k = "keyence";
    int n = s.length();
    bool flag = false;
    for(int i=0; i<=7; i++) {
        string t = s.substr(0,(7-i)) + s.substr(n-i,i);
        if(k == t) flag = true;
    }
    if(flag) cout<<"YES"<<"\n";
    else cout<<"NO"<<"\n";
}