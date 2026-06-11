#include<bits/stdc++.h>
using namespace std;
                    
                    
int main(){
    string s, s1;
    cin >> s;
    int ans = 0;
    int c1, c2;
    c1 = 0;
    c2 = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '0'){
            c1++;
        } else {
            c2++;
        }
    }

    ans = 2 * min(c1, c2);

    cout << ans << endl;

    return 0;
            
}