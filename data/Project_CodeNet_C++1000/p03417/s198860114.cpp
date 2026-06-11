#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll N,M;
    cin >> N >> M;
    
    ll ans;

    if(N == 2 || M == 2)ans = 0;
    else if(N == 1 && M == 1)ans = 1;
    else if(N == 1 && M > 2)ans = M - 2;
    else if(M == 1 && N > 2)ans = N - 2;
    else ans = (M - 2) * (N - 2);

    cout << ans << endl;
}