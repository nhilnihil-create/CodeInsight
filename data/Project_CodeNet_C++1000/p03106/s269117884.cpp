#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ll ans = 0;
    ll A, B, N;
    ll div[100];
    cin >> A >> B >> N;

    ll count = 0;
    for (ll i = min(A, B); count != N; i--)
    {
        if(A % i == 0 && B % i == 0) {
            div[count] = i;
            count++;
            // cout << i << endl;
        }
    }
    
    cout << div[count - 1] << endl;

    return 0;
}
