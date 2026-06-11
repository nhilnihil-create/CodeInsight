#include <bits/stdc++.h>
using namespace std;

#define rep(i, a) for (int i = 0; i < (a); i++ )

 
typedef pair<int,int> P;
typedef long long ll;
 
const int INF = 1001001001;
const int MOD = 1000000007;
const double PI=acos(-1);

int main(){
    int N;
    cin >> N;
    ll A[N],B[N];
    map<ll,ll> S;
    rep(i,N) {
        int a;
        cin >> a;
        if (i==0) {
            A[i] = a;
            B[i] = a;
            S[a]++;
        }
        else {
            A[i] = a;
            B[i] = B[i-1] + a;
            S[B[i]]++;
        }
    }

    ll ans = 0;
    rep(i,N) {
        ll a = B[i];
        ll tmp = B[i]-A[i];
        ll s = S[tmp];
        ans += s;
        S[a]--;
    }
    cout << ans << endl;
}
