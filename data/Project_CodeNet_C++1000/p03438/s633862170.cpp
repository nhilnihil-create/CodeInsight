#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    vector<ll> A(N);
    for(int i=0; i<N; i++) cin >> A[i];
    vector<ll> B(N);
    for(int i=0; i<N; i++) cin >> B[i];

    string ans = "Yes";
    ll asum = accumulate(A.begin(), A.end(), 0LL);
    ll bsum = accumulate(B.begin(), B.end(), 0LL);
    if(asum > bsum) ans = "No";

    ll difsum = 0;
    for(int i=0; i<N; i++)
    {
        if(A[i] < B[i]) difsum += (B[i] - A[i] + 1) / 2;
    }
    if(bsum - asum < difsum) ans = "No";
    cout << ans << endl;

    return 0;
}
