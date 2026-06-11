#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#define abdelrahman010 ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;
using namespace std;
const int N = 1e3 + 5;
int x , y , z , k;
ll a[N] , b[N] , c[N];
int main() {
    abdelrahman010
    cin >> x >> y >> z >> k;
    for(int i = 0;i < x;i++)
        cin >> a[i];
    for(int i = 0;i < y;i++)
        cin >> b[i];
    for(int i = 0;i < z;i++)
        cin >> c[i];
    sort(a , a + x , greater<>());
    sort(b , b + y , greater<>());
    sort(c , c + z , greater<>());
    vector<ll> v;
    for(int i = 0;i < x;i++)
        for(int j = 0;j < y;j++)
            for(int l = 0;l < z;l++)
                if((i + 1) * (j + 1) * (l + 1) <= k)
                    v.push_back(a[i] + b[j] + c[l]);
                else
                    break;
    sort(v.rbegin() , v.rend());
    for(int i = 0;i < k;i++)
        cout << v[i] << '\n';
    return 0;
}
