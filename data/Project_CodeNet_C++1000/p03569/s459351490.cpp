#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    string S;
    cin >> S;
    ll N = S.size();
    ll lindex = 0;
    ll rindex = N-1;
    ll ans =0;
    while(lindex<rindex){
        if(S[lindex] != S[rindex]){
            if(S[lindex] == 'x'){
                ans++;
                lindex++;
                continue;
            }
            if(S[rindex] =='x'){
                ans++;
                rindex--;
                continue;
            }
            cout << -1 << endl;
            return 0;

        }else{
            lindex++;
            rindex--;
        }

    }
    cout << ans << endl;

    return 0;
}