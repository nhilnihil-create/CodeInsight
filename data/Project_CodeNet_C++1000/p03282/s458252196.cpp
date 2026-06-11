#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using P = pair<int,int>;
/* ちゃんと考えてわかって実装 */

int main(void){
    string s;
    cin >> s;
    ll k;
    cin >> k;

    char ans;
    if(k <= s.length()){
        ll ones = 0;
        for(int i=0; i<k; i++){
            if(s[i] == '1') ones++;
            else{
                ans = s[i];
                break;
            }
        }
        if(ones == k) ans = '1';
    }
    else{
        ll ones = 0;
        for(int i=0; i<s.length(); i++){
            if(s[i] == '1') ones++;
            else{
                ans = s[i];
                break;
            }
        }
        if(ones == s.length()) ans = '1';
    }
    cout << ans << endl;
    return 0;
}