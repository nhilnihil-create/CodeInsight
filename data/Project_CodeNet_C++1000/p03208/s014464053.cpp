#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pii pair<int , int>
#define _FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MAXX 100005

int n , k;
int p[MAXX];

int main()
{
    _FastIO;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> p[i];
    }
    sort(p , p + n);
    int ans = p[n - 1] - p[0];
    for(int i = k - 1; i < n; i++){
        ans = min(ans , (p[i] - p[i - k + 1]));
    }
    cout << ans << endl;
    return 0;
}
