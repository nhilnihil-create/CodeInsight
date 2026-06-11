#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
#define ll long long
#define ld long double
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define PI 3.14159265358979323846
#define sz(x) ((int)(x).size())
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)
#define all(x) (x).begin(),(x).end()

const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;
int main()
{
    int n;cin >> n;
    vector<ll> a(n);rep(i,n)cin >> a[i];
    vector<ll> ruiseki(n);
    ll temp = 0;
    rep(i,n)
    {
        temp += a[i];
        ruiseki[i] = temp;
    }
    map<ll,ll>mp;
    rep(i,n)
    {
        mp[ruiseki[i]]++;
    }
    ll ans = 0;
    for (auto &&i : mp)
    {
        if(i.first==0)
        {
            ans += i.second * (i.second + 1) / (ll)2;
            continue;
        }
        ans += i.second*(i.second-1)/(ll)2;
    }
    cout << ans << endl;
    


}