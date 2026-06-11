#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll N;
    cin >> N;
    ll a = 0, b = 0, ab = 0, ans = 0;
    rep(i, 0, N){
        string s;
        cin >> s;
        if(s[0] == 'B' && s[s.size()-1] == 'A') ab++;
        else if(s[0] == 'B') a++;
        else if(s[s.size()-1] == 'A') b++;
        rep(j, 0, s.size()-1){
            if(s[j] == 'A' && s[j+1] == 'B') ans++;
        }
    }
    
    if(a == 0 && b == 0){
        if(ab > 0) ans += ab - 1;
    }else if(a == 0 || b == 0){
        ans += ab;
    }else{
        if(ab == 0) ans += min(a, b);
        else ans += ab + min(a, b); 
    }

    cout << ans << endl;
    return 0;
}