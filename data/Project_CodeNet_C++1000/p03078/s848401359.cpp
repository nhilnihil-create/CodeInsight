#include<bits/stdc++.h>
using namespace std;

#define LL long long
LL x, y, z, u, d;
vector<LL> a, b, c;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    cin >> x >> y >> z >> d;

    for(int i = 0; i < x; i++) cin >> u, a.push_back(u);
    for(int i = 0; i < y; i++) cin >> u, b.push_back(u);
    for(int i = 0; i < z; i++) cin >> u, c.push_back(u);

    sort(a.rbegin(), a.rend()), sort(b.rbegin(), b.rend()), sort(c.rbegin(), c.rend());
    
    vector<LL> ans, f;
    for(int i = 0; i < x; i++) 
        for(int j = 0; j < y; j++)
            f.push_back(a[i] + b[j]);
    sort(f.rbegin(), f.rend());

    for(int i = 0; i < min(x*y, d); i++)
        for(int j = 0; j < z; j++)
            ans.push_back(f[i] + c[j]);
    sort(ans.rbegin(), ans.rend());

    for(int i = 0; i < d; i++) cout << ans[i] << '\n';
}