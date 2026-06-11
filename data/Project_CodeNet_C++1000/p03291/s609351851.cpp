#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
#define reps(i,s,n) for(int i = s; i < n; i++)
#define rep(i,n) reps(i,0,n)
#define fi first
#define se second
#define mp make_pair
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;

ll N,M,H,W,K,Q,A,B,L,R;
string S,T;
const ll MOD = (1e+9) + 7;
const ll INF = 1LL << 60;
typedef pair<ll,ll> P;

typedef vector<P> vp;
typedef vector<vp> matP;

int main(){
    cin>>S;
    N = S.size();
    mat left(N+1,vec(2,0)), right(N+1,vec(2,0));
    reps(i,1,N+1){
        left[i][0] = left[i-1][0] + (S[i-1] == 'A');
        left[i][1] = left[i-1][1] + (S[i-1] == '?');
        right[i][0] = right[i-1][0] + (S[N-i] == 'C');
        right[i][1] = right[i-1][1] + (S[N-i] == '?');
    }
    ll ans = 0;
    vec bit3(100010,1);
    reps(i,1,100010) (bit3[i] *= bit3[i-1]*3)%=MOD;
    reps(i,1,N-1){
        if(S[i] == 'B' || S[i] == '?'){
            vec l = left[i], r = right[N-1-i];
            L = (l[0] * bit3[l[1]])%MOD;
            if(l[1] > 0) (L += (l[1] * bit3[l[1] - 1])%MOD)%=MOD;
            R = (r[0] * bit3[r[1]])%MOD;
            if(r[1] > 0) (R += (r[1] * bit3[r[1] - 1])%MOD)%=MOD;
            (L *= R)%=MOD;
            (ans += L)%=MOD;
        }
    }
    cout<<ans<<endl;
}
