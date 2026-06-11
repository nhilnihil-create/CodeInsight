#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
using namespace std;
const int N = 1e5+5;
int h[N],n,k,ans[N];
main() {
    cin >> n;
    k = 2;
    cin >> k;
    for (int i = 1; i <= n; i++)
        cin >> h[i];
    for (int i = 2; i <= n; i++) {
            ans[i] = 1000000000;
        for (int j = max(1,i - k); j < i; j++)
        ans[i] = min(ans[i],ans[j] + abs(h[i] - h[j]));
    }
    cout << ans[n];




}
