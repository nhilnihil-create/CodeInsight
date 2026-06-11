#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    string t;
    for ( int i=0; i<s.size(); i++ ) {
        if ( s[i]=='A' ) {  t+='A'; }
        else if ( i+1<s.size()&&s[i]=='B'&&s[i+1]=='C' ) { t+='D'; i++; }
        else { t+=s[i]; }
    }
    long long ans=0,cnt=0;
    for ( int i=(int)t.size()-1; i>=0; i-- ) {
        if ( t[i]=='D' ) {
            cnt++;
        } else if ( t[i]=='A' ) {
            ans+=cnt;
        } else {
            cnt=0;
        }
    }
    cout << ans  << '\n';
    return 0;
}