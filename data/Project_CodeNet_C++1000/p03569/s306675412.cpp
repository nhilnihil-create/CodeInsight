#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    string s;
    cin >> s;
    ll ans = 0;
    ll hd = 0, bk = s.size()-1;
    while(bk - hd > 0){
        if(s[hd] == s[bk]){
            hd++;
            bk--;
        }else{
            if(s[hd] != 'x' && s[bk] != 'x'){
                cout << -1 << endl;
                return 0;
            }
            if(s[hd] == 'x'){
                ans++;
                hd++;
            }
            if(s[bk] == 'x'){
                ans++;
                bk--;
            }
        }
    }
    cout << ans << endl;
    return 0;
}