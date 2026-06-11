#include <bits/stdc++.h>
#define Phuong_ ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back
#define mp make_pair

/// easy access -------------
using namespace std;
using ll = long long;
using ld = long double;
typedef pair<int,int> pii;
///-------------------------

int main()
{
    Phuong_; /// <3
    int n;
    cin >> n;
    ll sum=0;
    vector<ll> a(n);
    for(ll i=1; i<=n; ++i)
    {
        ll u;
        cin >>u;
        u-=i;
        a[i-1]=u;
    }
    sort(a.begin(), a.end());
    sum=0;
    for(int i=0; i<n; ++i)
    {
        sum+=abs((a[i]-a[n/2]));
    }
    cout << sum;
    return 0;
}

