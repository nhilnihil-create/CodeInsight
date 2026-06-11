#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pii pair<int ,int>
#define _FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MAXX 1005

int n , m , k , t;
int a[MAXX];

int main()
{
    _FastIO;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> k;
        for(int j = 0; j < k; j++){
            cin >> t;
            a[t]++;
        }
    }
    int ans = 0;
    for(int i = 0; i < 31; i++){
        if(a[i] == n)
            ans++;
    }
    cout << ans << endl;
    return 0;
}
