#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll N;
    cin >> N;
    vector<ll> A(N), B(N), C(N);
    for(ll i = 0; i < N; i++){
        cin >> A.at(i);
    }
    for(ll i = 0; i < N; i++){
        cin >> B.at(i);
    }
    for(ll i = 0; i < N; i++){
        cin >> C.at(i);
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(C.begin(), C.end());
    ll key, sum = 0;
    for(ll i = 0; i < N; i++){
        key = B.at(i);
        vector<ll>::iterator d1, d2;
        d1 = lower_bound(A.begin(), A.end(), key);
        d2 = upper_bound(C.begin(), C.end(), key);
        ll rd1 = distance(A.begin(), d1);
        ll rd2 = N - distance(C.begin(), d2);

        sum += rd1 * rd2;
    }
    cout << sum << endl;
    return 0;

}