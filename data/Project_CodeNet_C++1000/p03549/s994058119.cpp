#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define All(V) V.begin(), V.end()
typedef long long int ll;
typedef pair<int, int> P;
const ll MOD = 1e9+7, INF = 1e9;

int main()
{
    int n, m; cin >> n >> m;
    ll ans = 0;
    ans = 1900*m + 100*(n-m);
    rep(i, m){
        ans *= 2;
    }
    cout << ans << endl;
    system("pause");
}