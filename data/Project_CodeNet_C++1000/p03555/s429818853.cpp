#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<string>v(2), tmp;
    cin >> v[0] >> v[1];
    tmp = v;
    reverse(v[0].begin(), v[0].end());
    reverse(v[1].begin(), v[1].end());
    reverse(v.begin(), v.end());
    cout << (v == tmp ? "YES" : "NO");
    return 0;
}
