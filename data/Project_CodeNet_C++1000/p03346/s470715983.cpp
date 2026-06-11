// be name khoda
#include<bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define int long long
#define mpr make_pair 
typedef long long ll;
#pragma GCC optimize("Ofast")

const int maxn = 3e5+10;
const int N = 1e6+5;
const int mod = 998244353;
const int inf = 1e9+10;

int n, k;
int a[maxn], pos[maxn];

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>> n;
    for(int i = 1; i <= n; i++)
    {
        cin>> a[i];
        pos[a[i]] = i;
    }

    int ans = n-1, d = 1;
    for(int i = 2; i <= n; i++)
    {
        if(pos[i] > pos[i-1]) d++;
        else d = 1;
        ans = min(ans,n-d);
    }
    cout<< ans;
}



