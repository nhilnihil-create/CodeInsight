#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ll N = 0;
    cin >> N;
    int ans = 0;
    vector<ll> A(N,0);
    for(ll i = 0; i < N; i++) {
        cin >> A.at(i);
    }

    for(int i = 0; i < N; i++) {
        //cout << A.at(i) << endl;
        while(!(A.at(i)%2)) {
            ans++;
            //cout << "##" << endl;
            A.at(i) /= 2;
        }
    }

    cout << ans << endl;



    return 0;
}