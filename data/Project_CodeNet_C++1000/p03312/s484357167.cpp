#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAXN = 200000;
const ll INF = 1001001001;
const ll MOD = 1000000007;

ll N, ans=INF, tmp=0, tmpi;
vector<ll> A, S1, S2;

signed main(){
    cin >> N;
    for(int i=0;i<N;i++) {
        ll a;
        cin >> a;
        A.push_back(a);
    }
    S1.resize(N);
    S1[0] = A[0];
    for(int i=0;i<N-1;i++) {
        S1[i+1] = S1[i] + A[i+1];
    }
    S2.resize(N);
    S2[N-1] = A[N-1];
    for(int i=N-2;i>=0;i--) {
        S2[i] = S2[i+1] + A[i];
    }
    reverse(S2.begin(), S2.end());
    for(int i=1;i<N-2;i++) {
        ll id1 = lower_bound(S1.begin(), S1.end(), S1[i]/2)-S1.begin();
        tmp = INF;
        if(id1<i) {
            tmp = abs(S1[i]-2*S1[id1]);
            tmpi = id1;
        }
        if(id1>0) {
            if(tmp>abs(S1[i]-2*S1[id1-1LL])) {
                tmp = abs(S1[i]-2*S1[id1-1LL]);   
                tmpi = id1-1;
            }
        }
        ll P = S1[tmpi];
        ll Q = S1[i] - S1[tmpi];
        ll id2 = lower_bound(S2.begin(), S2.end(), S2[N-i-2]/2)-S2.begin();
        tmp = INF;
        if(id2<N-i-2) {
            tmp = abs(S2[N-i-2]-2*S2[id2]);
            tmpi = id2;
        }
        if(id2>0) {
            if(tmp>abs(S2[N-i-2]-2*S2[id2-1LL])) {
                tmp = abs(S2[N-i-2]-2*S2[id2-1LL]);   
                tmpi = id2-1;
            }
        }
        ll R = S2[tmpi];
        ll S = S2[N-i-2] - S2[tmpi];
        ll minv, maxv;
        minv = min(R, S);
        minv = min(minv, P);
        minv = min(minv, Q);
        maxv = max(R, S);
        maxv = max(maxv, P);
        maxv = max(maxv, Q);
        ans = min(ans, maxv-minv);
    }
    cout << ans << endl;
    return 0;
}