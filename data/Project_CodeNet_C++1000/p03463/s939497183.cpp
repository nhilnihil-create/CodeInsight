#include <bits/stdc++.h>

#define REP(i, n) for(int (i)=0;(i)<(n);++(i))
#define REPV(iter, v) for(auto (iter)=(v).begin(); (iter)!=(v).end();++(iter))
#define ALL(v) (v).begin(),(v).end()

#define MOD 1000000007

using namespace std;

typedef long long ll;

int main()
{
    ll N, A, B;
    cin >> N >> A >> B;

    string ans = (B - A) % 2 == 0 ? "Alice" : "Borys";

    cout << ans << endl;
}
