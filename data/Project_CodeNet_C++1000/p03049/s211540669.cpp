#include <bits/stdc++.h>
#define FOR(i, l, r) for(ll i = l; i < r; i++)
#define rep(i, N) FOR(i, 0, N)
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<ll> vl;
const ll MOD = round(1e9+7);

int main() {
    int N; cin >> N;
    vector<string> S(N); rep(i,N) cin >> S[i];
    int BA = 0, A = 0, B = 0;
    int ans = 0;

    rep(i,N){
        if(S[i][0] == 'B') B++;
        if(S[i][(int)S[i].size()-1] == 'A') A++;
        if(S[i][0] == 'B' && S[i][(int)S[i].size()-1] == 'A') BA++;
        rep(j,(int)S[i].size()-1){
            if(S[i].substr(j,2) == "AB") ans++;
        }
    }

    if(BA > 0){
        A -= BA; B -= BA;
        ans += BA-1;
        if(A > 0) {ans++; A--;}
        if(B > 0) {ans++; B--;}
    }
    ans += min(A,B);
    

    cout << ans;
    return 0;
}
