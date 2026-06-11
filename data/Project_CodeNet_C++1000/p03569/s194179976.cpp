#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAXN = 200000;

ll N, ans=0, tmp=0;
vector<ll> A;
string S, T="";

signed main(){
    cin >> S;
    for(int i=0;i<S.size();i++) {
        if(S[i]!='x') {
            T = T+S[i];
            A.push_back(tmp);
            tmp=0;
        }
        else {
            tmp++;
        }
    }
    //cout << T << endl;
    A.push_back(tmp);
    for(int i=0;i<T.size();i++) {
        if(T[i]!=T[T.size()-1-i]) {
            cout << -1 << endl;
            return 0;
        }
    }
    for(int i=0;i<A.size();i++) {
        if(i<A.size()-1-i) ans += abs(A[i]-A[A.size()-1-i]);
    }
    cout << ans << endl;
    return 0;
}