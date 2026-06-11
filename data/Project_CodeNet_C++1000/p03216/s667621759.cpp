#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int N;
    string S;
    int Q;
    cin >> N >> S >> Q;
    
    for (int i = 0; i < Q; i++) {
        int k;
        cin >> k;
        ll dn = 0, mn = 0, dmn = 0;
        ll ans = 0;
        for (int j = 0; j < N; j++) {
            if (j >= k) {
                if (S[j-k] == 'D') {
                    dn--;
                    dmn -= mn;
                }
                else if (S[j-k] == 'M') mn--;
            }
            if (S[j] == 'D') dn++;
            else if (S[j] == 'M') {
                mn++;
                dmn += dn;
            }
            else if (S[j] == 'C') ans += dmn;
        }
        cout << ans << endl;
    }
    
    return 0;
}
