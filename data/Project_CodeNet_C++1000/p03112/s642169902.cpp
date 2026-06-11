#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

const ll INF = 100100100100;

int main() {
    int A, B, Q; cin >> A >> B >> Q;
    vector<ll> S(A);
    vector<ll> T(B);
    vector<ll> X(Q);
    rep(i, A){
        cin >> S[i];
    }
    rep(i, B){
        cin >> T[i];
    }
    rep(i, Q){
        cin >> X[i];
    }

    rep(i, Q){
        ll x = X[i];
        int ss = lower_bound(S.begin(), S.end(), x) - S.begin();
        int tt = lower_bound(T.begin(), T.end(), x) - T.begin();
        if(ss == 0){
            if(tt == 0){
                cout << max(S[0], T[0]) - x << endl;
                continue;
            } else {
                ll d1;
                if(tt != B){
                    d1 = max(T[tt], S[0]) - x;
                } else {
                    d1 = INF;
                }
                ll d2 = min((S[0]- x) * 2 + x - T[tt-1], (x - T[tt-1]) * 2 + S[0] - x);
                cout << min(d1, d2) << endl;
                continue;
            }
        }

        if(tt == 0){
            ll d1;
            if(ss != A){
                d1 = max(S[ss], T[0]) - x;
            } else {
                d1 = INF;
            }
            ll d2 = min((T[0]- x) * 2 + x - S[ss-1], (x - S[ss-1]) * 2 + T[0] - x);
            cout << min(d1, d2) << endl;
            continue;
        }

        if(ss == A){
            if(tt == B){
                cout << x - min(S[A-1], T[B-1]) << endl;
                continue;
            } else {
                ll d1 = x - min(T[tt-1], S[A-1]);
                ll d2 = min((T[tt]- x) * 2 + x - S[A-1], (x - S[A-1]) * 2 + T[tt] - x);
                cout << min(d1, d2) << endl;
                continue;
            }
        }

        if(tt == B){
            ll d1 = x - min(S[ss-1], T[B-1]);
            ll d2 = min((S[ss]- x) * 2 + x - T[B-1], (x - T[B-1]) * 2 + S[ss] - x);
            cout << min(d1, d2) << endl;
            continue;
        }

        ll ans1, ans2, ans3, ans4;
        ans1 = max(T[tt], S[ss]) - x;
        ans2 = x - min(T[tt-1], S[ss-1]);
        if(S[ss] < T[tt]){
            ans3 = (S[ss] - x) * 2 + x - T[tt-1];
        } else {
            ans3 = (T[tt] - x) * 2 + x - S[ss-1];
        }
        if(S[ss-1] < T[tt-1]){
            ans4 = (x - T[tt-1]) * 2 + S[ss] - x;
        } else {
            ans4 = (x - S[ss-1]) * 2 + T[tt] - x;
        }
        ans1 = min(ans1, ans2);
        ans1 = min(ans1, ans3);
        ans1 = min(ans1, ans4);

        cout << ans1 << endl;



    }

    return 0;
}