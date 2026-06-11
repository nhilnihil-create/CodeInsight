#include <bits/stdc++.h>

using namespace std;
#define  ll long long
#define ld long double
#define f first
#define s second
const int N = 1e5+5;

ll n , m;
vector<ll> a;
vector< pair<ll,ll> > b;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for(int i=1; i<=n; i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }

    for(int i=1; i<=m; i++)
    {
        int x,y;
        cin >> x >> y;
        b.push_back({y,x});
    }

    sort(b.begin() , b.end()) , sort(a.begin() , a.end() , greater<ll>() );

    ll ans = 0;
    while(b.size())
    {
        ll cnt = b.back().s , tmp = b.back().f;
        while(cnt > 0 && a.size() && a.back() < tmp)
        {
            cnt--;
            ans += tmp;
            a.pop_back();
        }
        b.pop_back();
    }
    while(a.size())
    {
        ans += a.back();
        a.pop_back();
    }
    cout << ans << '\n';
	//
  
    return 0;
}