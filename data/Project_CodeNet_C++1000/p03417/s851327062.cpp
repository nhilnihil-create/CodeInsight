#include <bits/stdc++.h>

#define REP(i, n) for(int (i)=0;(i)<(n);++(i))
#define REPV(iter, v) for(auto (iter)=(v).begin(); (iter)!=(v).end();++(iter))
#define ALL(v) (v).begin(),(v).end()

#define MOD 1000000007

using namespace std;

typedef long long ll;

int main()
{
    ll N, M;
    cin >> N >> M;
    ll ans;
    if (N == 1 && M == 1) 
    {
        ans = 1;
    }
    else if (N == 1)
    {
        ans = max(0ll, M - 2);
    }
    else if (M == 1)
    {
        ans = max(0ll, N - 2);
    }
    else
    {
        ans = (N - 2) * (M - 2);
    }
    

    cout << ans << endl;
}
