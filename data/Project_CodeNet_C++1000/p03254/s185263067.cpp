#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){

    ll N, x;
    cin >> N >> x;

    vector<int> a(N);
    for (ll i=0; i<N; i++){
        cin >> a.at(i);
    }

    sort(a.begin(), a.end());

    ll ans = 0;
    for (ll i=0; i<N; i++){
        x -= a.at(i);
        ans++;

        if (x<0) {
            ans--;
            break;
        }
    }
    if (x > 0){
        ans--;
    }

    cout << ans << endl;
    return 0;
}