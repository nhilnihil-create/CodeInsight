#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define endl "\n" 
#define p pair<int, int>
#define arrinp(i, a, start, end); for(ll i = start; i <= end; i++) cin >> a[i];
#define arrout(i, a, start, end); for(ll i = start; i <= end; i++) cout << a[i] << " ";
#define swap(a, b) {a = a + b; b = a - b; a = a - b;
#define forfront(i, start, end) for(ll i = start; i <= end; i++)
#define forback(i, start, end) for(ll i = start; i >= end; i--)
#define out(x) cout << x << " "
#define outline(x) cout << x << endl;
int main()
{
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int d, n;
    cin >> d >> n;
    if(n==100)n++;
    ll ans = pow(100, d);
    ans *= n;
    outline(ans);
    return 0;
}