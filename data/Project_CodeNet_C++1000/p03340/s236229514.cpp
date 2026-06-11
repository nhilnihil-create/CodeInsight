#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<int> A(N);

    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int R = 0;
    ll ans = 0;
    ll count = 0;

    for(int i = 0; i < N; i++) {

        if(A[i] & R) {
            ans += count * (count + 1LL) / 2LL;
            count = 1LL;
            R = A[i];
            ll c = 0;
            for(int j = i - 1; !(R & A[j]); j--) {
                c++;
                count++;
                R |= A[j];
            }
            ans -= c * (c + 1LL) / 2LL;
        } else { 
            R |= A[i];
            count++;
        }
    }

    ans += count * (count + 1LL) / 2LL;

    cout << ans << endl;
}