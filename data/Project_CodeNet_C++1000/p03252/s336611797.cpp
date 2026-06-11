#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAXN = 200000;

string S, T, ST;
set<ll> A[26], B[26];

signed main(){
    cin >> S >> T;
    if(S.size()!=T.size()) {
        cout << "No" << endl;
        return 0;
    }
    for(int i=0;i<S.size();i++) {
        ll si = S[i]-'a';
        ll ti = T[i]-'a';
        A[si].insert(ti);
        B[ti].insert(si);
    }
    for(int i=0;i<26;i++) {
        //cout << i << " : " << A[i].size() << " : " << B[i].size() << endl;
        if(A[i].size()>=2||B[i].size()>=2) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}