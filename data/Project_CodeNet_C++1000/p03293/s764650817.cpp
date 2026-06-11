#include <bits/stdc++.h>
using namespace std;  

int main(){
    string s, t, ans;
    int same;
    
    cin >> s >> t;
    ans = "No";
    
    for ( int i = 0; i < s.size(); i++ ) {
        same = 0;
        for ( int j = 0; j < s.size(); j++ ) {
            if (s[(i+j)%s.size()] == t[j]) {
                same++;
            }
        }
        
        if ( same == s.size() ) {
            ans = "Yes";
        }
    }
    
    cout << ans << endl;
    
    return (0);
}
