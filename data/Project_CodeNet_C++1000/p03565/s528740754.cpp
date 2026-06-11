#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAXN = 200000;

ll N, ans=0, tmp=0;
vector<ll> A(MAXN, 0);
string S, T;

signed main(){
    cin >> S >> T;
    if(S.size()<T.size()) {
        cout << "UNRESTORABLE" << endl;
        return 0;
    }
    if(S.size()==T.size()) {
        for(int i=0;i<T.size();i++) {
            if(S[i]=='?') continue;
            if(S[i]!=T[i]) {
                cout << "UNRESTORABLE" << endl;
                return 0;
            }
        }
        cout << T << endl;
        return 0;
    }
    for(int i=S.size()-T.size();i>=0;i--) {
        ll flag=0;
        for(int j=0;j<T.size();j++) {
            if(S[i+j]=='?') continue;
            if(S[i+j]!=T[j]) {
                flag=1;
            }
        }
        if(flag==0) {
            for(int k=0;k<S.size();k++) {
                if(k<=i+T.size()-1&&k>=i) {
                    cout << T[k-i];
                }
                else {
                    if(S[k]=='?') cout << 'a';
                    else cout << S[k];
                }
            }
            return 0;
        }
    }
    cout << "UNRESTORABLE" << endl;
    return 0;
}