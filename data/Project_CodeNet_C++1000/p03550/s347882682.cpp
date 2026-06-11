#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const static ll INF = 1e9;
const static ll MOD = 1e9+7;


int main(){
    ll N, Z, W; cin >> N >> Z >> W;
    vector<ll> A(N); for(ll i = 0; i < N; i++) cin >> A[i];
    vector<ll> ADP(N), BDP(N);
    if(N == 1){
        cout << abs(A[0] - W) << endl;
        return 0;
    }
    ADP[N-1] = abs(A[N-1]-W);
    ADP[N-2] = abs(A[N-1] - A[N-2]);
    BDP[N-2] = ADP[N-2]; 
    ll Amax, Bmin;
    Amax = max(ADP[N-2], ADP[N-1]);
    Bmin = BDP[N-2];
    for(ll i = N-3; i >= 0; i--){
        ll amax=Amax, bmin=Bmin;
        ADP[i] = min(bmin, (ll)abs(A[i]- A[N-1]));
        BDP[i] = max(amax, (ll)abs(A[i]- A[N-1]));
        Amax = max(Amax, ADP[i]);
        Bmin = min(Bmin, BDP[i]);
        //if(i != 0) BDP[i] = max(ADP[i+1], (ll)abs(A[i]- A[N-1]));
        


    }
    ll Max = 0;
    //Max = max(A[N-1], Amin);
    for(ll i = 0; i < N; i++) if(Max < ADP[i]) Max = ADP[i];
    cout << Amax << endl;



}