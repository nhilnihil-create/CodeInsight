#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ll N;
    cin >> N;
    vector<ll> A;
    for (ll i = 0; i < N; ++i)
    {
        ll temp;
        cin >> temp;
        A.push_back(temp);
    }
    double sum = 0;
    for (ll l : A)
    {
        sum += l;
    }
    double avr = sum / N;
    double mini = 1000000;
    ll ans = 0;
    for (ll i = 0; i < N; ++i)
    {
        if (mini > abs(A[i] - avr))
        {
            ans = i;
            mini = abs(A[i] - avr);
        }
    }
    cout << ans << endl;
}
