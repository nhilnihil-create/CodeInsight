#include <bits/stdc++.h>

#define REP(i, n) for(int (i)=0;(i)<(n);++(i))
#define REPV(iter, v) for(auto (iter)=(v).begin(); (iter)!=(v).end();++(iter))
#define ALL(v) (v).begin(),(v).end()

#define MOD 1000000007

using namespace std;

typedef long long ll;

int main()
{
    ll A, B, C, K;
    cin >> A >> B >> C >> K;

    ll ans = K % 2 == 0 ? A - B : B - A;

    cout << ans << endl;
}
