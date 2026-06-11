// be name khoda
#include<bits/stdc++.h>

using namespace std;

#define F first
#define S second
//#define mp make_pair 
typedef long long ll;
#define int long long
#pragma GCC optimize("Ofast")

const int maxn = 2e5+10;
const int mod = 1e9+7;
const ll inf = 1e18+10;
//const int N = 2e6+10;

ll pw(ll a, ll b)
{
    if(b == 0) return 1;
    ll x = pw(a,b/2); x = (x*x) % mod;
    if(b & 1) x = (x*a) % mod;
    return x;
}

int n;
int a[maxn];

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>> n;
    map<int,int> cnt;
    for(int i = 1; i <= n; i++) 
    {
        cin>> a[i];    
        cnt[a[i]]++;
    }
    sort(a+1,a+n+1);

    int ans = 0;
    for(int i = n; i >= 1; i--)
    {
        int x = log2(a[i])+1;
        int y = (1ll<<x);
        cnt[a[i]]--;
        if(cnt[y-a[i]] >= 1 && cnt[a[i]] >= 0)
        {
           // cout<< i <<" "<< a[i] <<" "<< y-a[i] <<"\n";
            ans++;
            cnt[y-a[i]]--;
        }
        //cout<< i <<" ";
    }
    cout<< ans;
}
