#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;

    long long int ans = 0;
    long long int count = 0;
    for(int i=0; i<s.length(); i++){
        if(s[i] == 'B') count += 1;
        if(s[i] == 'W') ans += count;
    }
    cout << ans << endl;
    return 0;
}