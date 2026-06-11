/*** author: yuji9511 ***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> lpair;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " \n"[i==n-1];};
ll gcd(ll a,ll b){return b ? gcd(b, a % b) : a;} //最大公約数
int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    while(T--) {
        ll A,B,C,D;
        cin >> A >> B >> C >> D;
        if(A < B){
            print("No");
        }else if(B > D){
            print("No");
        }else if(C >= B-1){
            print("Yes");
        }else{
            // C+1=2, B-1=
            // C+1 <= (A + kD) mod B <= B-1
            // C+1-A <= kD mod B <= B-A-1
            ll L = ((C - A + 1) % B + B) % B;
            ll R = ((B - A - 1) % B + B) % B;
            if(L <= R){
                ll v = gcd(B, D);
                if(R / v == L / v && L % v != 0){
                    print("Yes");
                }else{
                    print("No");
                }

            }else{
                // k=0の時、つまりAがこれを満たす
                print("No");
            }
        }
    }
}