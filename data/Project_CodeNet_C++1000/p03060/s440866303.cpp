#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pii pair<int , int>
#define _FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MAXX 1005

int n , ans;
int v[MAXX];
int c[MAXX];

int main()
{
    _FastIO;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    for(int i = 0; i < n; i++){
        cin >> c[i];
        ans += (max(0 , (v[i] - c[i])));
    }
    cout << ans << endl;
    return 0;
}
