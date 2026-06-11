#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < n; i++)

typedef long long ll;
using namespace std;
int mod = 1000000007;

int main(void){
    string S; cin >> S;
    int lenS = S.length();
    int m = lenS/2;
    int l = m, r = m;
    if(lenS % 2 == 0) l--;

    if(lenS == 1) cout << 1 << endl;
    else{
        if(S[l] == '1' && S[r] == '1'){
            rep(i, lenS){
                if(S[i] == '0') S[i] = '1';
                else S[i] = '0';
            }
        }
        while(l >= 0 && S[l] == '0') l--;
        while(r < lenS && S[r] == '0') r++;
        if(l == -1 && r == lenS) cout << lenS << endl;
        else{
            if(l == -1){
                cout << r << endl;
            }
            else if(r == lenS){
                cout << lenS - (l+1) << endl;
            }
            else{
                cout << min(lenS - (l+1), r) << endl;
            }
        }
    }

    return 0;
}