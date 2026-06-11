#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define All(V) V.begin(), V.end()
typedef long long int ll;
typedef pair<int, int> P;
const ll MOD = 1e9+7, INF = 1e9;

int main()
{
    int n; cin >> n;
    vector<int> v(n);
    rep(i, n) cin >> v[i];
    sort(All(v), greater<int>());
    int ans = 0, t = 0;
    for(int i = 1; i < n; i++){
        int d = min(v[i], abs(v[0]-v[i]));
        if(d > t){
            t = d;
            ans = v[i];
        }
    }
    cout << v[0] << " " << ans << endl;

    system("pause");
}