#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    long long int ans = 0, a = 0, b = 0, c = 0;
    vector<string> s(n);
    for(int i=0; i<n; i++){
        cin >> s[i];
        for(int j=0; j+1<s[i].length(); j++){
            if(s[i][j] == 'A' && s[i][j+1] == 'B') ans += 1;
        }

        if(s[i][0] == 'B' && s[i][s[i].length()-1] == 'A') c += 1;
        else if(s[i][0] == 'B') b += 1;
        else if(s[i][s[i].length()-1] == 'A') a += 1;
    }
    
    if(c == 0) ans += min(a,b);
    else{
        if(a == 0 && b == 0) ans += c - 1;
        else ans += min(a,b) + c;
    }
    cout << ans << endl;
    return 0;
}