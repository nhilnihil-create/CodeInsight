#include <iostream>

using namespace std;

typedef long long ll;

ll N;
ll A[100005];
ll MOD=1e9+7;

ll coeff[100005];
ll nf;

ll mod_inv(ll a, ll m) {
        a = a%m;
        ll s0=0,s1=1,s2=m;
        ll t0=1,t1=0,t2=a;
        while (t2 != 0) {
                ll q = s2/t2;
                ll r0=t0,r1=t1,r2=t2;
                t0=s0-q*t0,t1=s1-q*t1,t2=s2-q*t2;
                s0=r0,s1=r1,s2=r2;
        }

        return (s0%MOD + MOD)%MOD;
}

int main() {
        cin >> N;
        for (int i=0; i<N; i++)
                cin >> A[i];

        nf = 1;
        for (int i=1; i<=N; i++)
                nf = (i*nf)%MOD;

        coeff[0] = 0;
        for (int i=1; i<=N; i++)
                coeff[i] = (coeff[i-1] + (nf*mod_inv(i,MOD))%MOD)%MOD;

        ll ret=0;
        for (int i=0; i<N; i++) {
                ret += (A[i]*((coeff[i+1] + coeff[N-i] - nf + MOD)%MOD))%MOD;
                ret %= MOD;
        }

        cout << ret << endl;
}