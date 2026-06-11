#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long 
using namespace std;
const ll INF = 1e18+10;
const ll N = 100010;
ll n, a[N], lim, d[N], c[N], res;

void chkMax(ll &x, ll y){if (x < y) x = y;}
void chkMin(ll &x, ll y){if (x > y) x = y;}

void Msort(ll l, ll r)
{
    if (l == r) return;
    ll mid = (l+r)>>1;
    Msort(l, mid);
    Msort(mid+1, r);
    ll i = l, j = mid+1, k = l;
    while (i <= mid && j <= r){
        if (d[i] <= d[j]){
            c[k++] = d[i++];
            res += r-j+1;
        }
        else
            c[k++] = d[j++];
    }
    while (i <= mid) c[k++] = d[i++];
    while (j <= r) c[k++] = d[j++];
    for (ll o = l; o <= r; o++)
        d[o] = c[o];
}

bool Check(ll mid)
{
    d[0] = 0;
    for (ll i = 1; i <= n; i++){
        d[i] = d[i-1];
        if (a[i] >= mid)
            d[i]++;
        else
            d[i]--;
    }
    res = 0;
    Msort(0, n);
    if (res >= lim) return true;
    return false;
}

int main()
{
    cin >> n;
    lim = (n*(n+1)/2+1)/2;
    ll l = INF, r = -INF, mid, ans;
    for (ll i = 1; i <= n; i++){
        cin >> a[i];
        chkMax(r, a[i]);
        chkMin(l, a[i]);
    }
    while (l <= r){
        mid = (l+r)>>1;
        if (Check(mid))
            ans = mid, l = mid+1;
        else
            r = mid-1;
    }
    cout << ans;
    return 0;
}