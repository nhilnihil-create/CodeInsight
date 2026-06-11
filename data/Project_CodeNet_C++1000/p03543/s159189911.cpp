#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    string s;
    cin >> s;
    if((s[0] == s[1] && s[1] == s[2])
        || (s[1] == s[2] && s[2] == s[3])){
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
    return 0;
}