#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);

const int N = 1e5+5, M = 1e6+6, OO = 0x3f3f3f3f;
int a[N], b[N];
int h, n;
int main()
{
    cin>>n>>h;
    int mxa = -1;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i]>>b[i];
        mxa = max(mxa, a[i]);
    }
    ll ans = 0;
    sort(b, b+n, greater<int>());
    for (int i = 0; i < n && h > 0 ; i++)
    {
        if(b[i] >= mxa)
        {
            h -= b[i];
            ans++;
        }
        else
            break;
    }
    if(h > 0)
        ans += (ll)(h + mxa - 1) / mxa ; 
    cout<<ans;
    
    return 0;
}