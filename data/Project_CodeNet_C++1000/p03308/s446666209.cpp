#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pii pair<int ,int>
#define _FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MAXX 1005

int a[MAXX];

int main()
{
    _FastIO;

    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a , a + n);
    cout << a[n - 1] - a[0] << endl;
    return 0;
}
