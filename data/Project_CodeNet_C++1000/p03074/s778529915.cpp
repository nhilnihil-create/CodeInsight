#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAXN = 200000;

ll N, K, ans=0, tmp=0, tmp2=0, pre=1;
vector<ll> A, B;
string S;

signed main(){
    cin >> N >> K >> S;
    for(int i=0;i<N;i++) {
        if(pre==S[i]-'0') {
            tmp++;
        }
        else {
            A.push_back(tmp);
            pre = 1-pre;
            tmp=1;
        }
    }
    A.push_back(tmp);
    if(pre==0) A.push_back(0);
    /*
    for(int i=0;i<A.size();i+=2) {
        cout << A[i] << endl;
        ans = max(ans, A[i]);
    }
    */
    for(int i=1;i<A.size();i++) {
        A[i] = A[i] + A[i-1];
    }
    for(int i=2*K;i<A.size();i+=2) {
        if(i==2*K) ans = max(ans, A[i]);
        else ans = max(ans, A[i]-A[i-2*K-1]);
    }
    if(2*K>=A.size()) ans = A.back();
    cout << ans << endl;
    return 0;
}