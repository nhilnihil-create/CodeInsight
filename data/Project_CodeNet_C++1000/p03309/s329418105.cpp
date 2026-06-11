#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll N;
    cin >> N;
    vector<ll> A(N);
    
    for(ll i = 0; i < N; i++)
    {
        ll tmp;
        cin >> tmp;
        tmp -= i+1;
        A[i] = tmp;
    }

    sort(A.begin(),A.end());
    ll middle = A[N / 2];
    ll ans = 0;

    for(ll i = 0; i < N; i++)
    {
        ans += abs(middle - A[i]);
    }
    
    cout << ans << endl;

}