#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define watch(x) cout << (#x) << " is " << (x) << endl
#define debug cout << "hi" << endl

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

ll gcd(ll a, ll b) {return (!b ? a : gcd(b, a % b));}
bool cmp(pair<ll,ll>a,pair<ll,ll>b){return a.first>b.first;}

const ll mod = 1e9 + 7;
const int INF32 = 1<<30;
const ll INF64 = 1LL<<60;
const ld pi = 3.141592653589793;

void solve(){
     int n,m;cin >> n >> m;
     vector<ll>a(n);
     for(int i = 0;i<n;i++) cin >> a[i];
     sort(a.begin(),a.end());
     vector< pair<ll,ll> >p;
     for(int i = 0;i<m;i++){
        int v,u;cin >> v >> u;
        p.push_back({u,v});
     }
     sort(p.begin(),p.end(),cmp);
     bool ok = 0;
     int idx = 0;
     for(int i = 0;i<m;i++){
        for(int j = 0;j<p[i].second;j++){
            if(idx==n){ok = 1;break;}
            if(p[i].first>a[idx]){
                a[idx] = p[i].first;
                 idx++;}
            else {
                ok = 1;break;
            }
        }
        if(ok) break;
     }
     ll sum = 0;
     for(int i = 0;i<n;i++) sum += a[i];
     cout << sum;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    solve();
    return 0;
}