#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ll n, q;
    string s;
    cin >> n >> s >> q;
    for(;q>0;q--){
        ll k, ans = 0, dcnt = 0, mcnt = 0, dmcnt = 0;
        cin >> k;
        for(int i=0;i<n;i++){
            if(s[i] == 'D') dcnt++;
            if(s[i] == 'M'){
                mcnt++;
                dmcnt += dcnt;
            }
            if(s[i] == 'C') ans += dmcnt;

            if(i>=k-1){
                if(s[i-k+1] == 'D'){
                    dcnt--;
                    dmcnt -= mcnt;
                }
                if(s[i-k+1] == 'M') mcnt--;
            }
        }
        cout << ans << endl;
    }
    return 0;
}