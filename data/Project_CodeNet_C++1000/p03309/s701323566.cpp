#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);
    
    ll N;
    cin >> N;

    vector<ll> A(N);

    for(ll i = 0; i < N; i++) {
        cin >> A[i];
        A[i] -= i + 1LL;

        //cout << A[i] << endl;
    }

    ll front = *min_element(A.begin(), A.end());

    for(ll i = 0; i < N; i++) {
        A[i] -= front;
    }

    ll left = 0;
    ll right = 2LL * pow(10, 10);

    ll ans = 0;

    while(left < right) {
        ll mid1 = (left + right) / 2;
        ll mid2 = mid1 + 1;
        ll count1 = 0;
        ll count2 = 0;
        for(int i = 0; i < N; i++) {
            count1 += abs(A[i] - mid1);
            count2 += abs(A[i] - mid2);
        }

        //cerr << mid1 << endl;

        if(count1 >= count2) {
            left = mid2;
            ans = count2;
        } else {
            right = mid1;
            ans = count1;
        }
    }

    cout << ans << endl;
}