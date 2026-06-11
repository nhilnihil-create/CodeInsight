#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using P = pair<ll,ll>;
/* ちゃんと考えてわかって実装 */

ll f(vector<ll> XX, ll b){
    ll res = 0;
    for(ll i=0; i<XX.size(); i++){
        res += abs(XX[i] - b);
    }
    return res;
}

int main(void){
    ll n;
    cin >> n;
    vector<ll> A(n);
    for(ll i=0; i<n; i++){
        cin >> A[i];
        A[i] -= (i+1);
    }
    sort(A.begin(), A.end());

    ll med1, med2, ans;
    if(n % 2 == 0){
        med1 = A[n/2];
        med2 = A[(n/2) - 1];
        ans = min(f(A, med1), f(A, med2));
    }
    else{
        med1 = A[n/2];
        ans = f(A, med1);
    }
    cout << ans << endl;
    return 0;
}