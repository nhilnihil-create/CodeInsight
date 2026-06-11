#include<bits/stdc++.h>

using namespace std;
using ll = long long int;

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);

    string s;
    cin >> s;
    if(s.size() == 1) {
        cout << s << endl;
        return 0;
    }

    bool a = true;
    for(ll i=1; i<s.size(); i++)
        if(s[i] != '9') a = false;
    cout << 9*(s.size()-1) + (s[0]-'0') - (!a) << endl;
}
