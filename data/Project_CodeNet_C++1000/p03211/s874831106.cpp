#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int ans = 753;
    for(int i=2; i<(int)s.length(); ++i){
        string t = s.substr(i-2, 3);
        int z = stoi(t);
        ans = min(ans, abs(753-z));
    }
    cout << ans;
    return 0;
}