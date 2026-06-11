#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ll N;
    cin >> N;
    vector<ll> A(N);
    vector<ll> left(N + 1);
    vector<ll> right(N + 1);
    for (ll i = 0; i < N; i++) {
        cin >> A.at(i);
    }
    if (N == 2) {
        cout << max(A.at(0),A.at(1)) << endl;
        return 0;
    }
    for (ll i = 0; i <= N; i++) {
        if (i == 0) {
            left.at(i) = A.at(i);
        }
        else {
            left.at(i) = __gcd(A.at(i - 1),left.at(i - 1));
        }
    }
    for (ll i = N; i >= 0; i--) {
        if (i == N) {
            right.at(i) = A.at(i - 1);
        }
        else {
            right.at(i) = __gcd(A.at(i),right.at(i + 1));
        }
    }
    ll ans;
    for (ll i = 0; i < N; i++) {
        if (i == 0) {
            ans = __gcd(left.at(i),right.at(i + 1));
        }
        else {
            ans = max(ans,__gcd(left.at(i),right.at(i + 1)));
        }
    }
    ll first = A.at(1);
    for (ll i = 1; i < N; i++) {
        first = __gcd(first,A.at(i));
    }
    ll fin = A.at(0);
    for (int i = 0; i < N - 1; i++) {
        fin = __gcd(fin,A.at(i));
    }
    cout << max(ans,max(first,fin)) << endl;
    /*for (int i = 0; i <= N; i++) {
        cout << left.at(i) << ' ' << right.at(i) << endl;
    }*/
}