#include<bits/stdc++.h>
#define MOD 1000000007
#define md 998244353
#define INF LLONG_MAX
#define F first
#define S second
#define sz(x) (long long)x.size()
#define vi vector<int>
#define vll vector<long long>
#define vpl vector<pair<long long,long long> >
#define vpi vector<pair<int,int> >
#define pb push_back
#define debug(x) cerr<<#x<<"= "<<x<<endl
#define all(v) v.begin(),v.end()
#define TT ll test;cin>>test; while(test--)
#define rep(i,a,n) for(ll i=a;i<(long long)n;++i)
#define repr(i,n,a) for(ll i=n;i>(long long)a;--i)
#define endl '\n'
#define MAXN 200005
typedef long long ll;
typedef long double ld;
using namespace std;
bitset<100005> bit;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);

    ll n,k;
    cin >> n >> k;
    vll a(n);
    for (int i = 0; i < n; ++i)
    {
    	cin >> a[i];
    }
    for (int i = 1; i <= k; ++i)
    {
    	for (int j = 0; j < n; ++j)
    	{
    		if(i >= a[j] && (!bit[i - a[j]])){
    			bit[i] = 1;
    		}
    	}
    }
    cout << (bit[k]?"First":"Second");

    return 0;
}