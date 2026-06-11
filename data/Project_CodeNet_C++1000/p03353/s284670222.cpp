#include <bits/stdc++.h>
 
#define gcd(m,n) __gcd(m,n)
#define lcm(m,n) m*(n/gcd(m,n))
#define fast std::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pi acos(-1.0)
#define endl '\n'
#define MOD 1000000007
#define ull unsigned long long
#define ll long long
#define ld long double
#define pb push_back
#define dbg(x) cout << #x << "  " << x << endl;
 
/* DSU 
int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}
void make_set(int v) {
    parent[v] = v;
    rank[v] = 0;
}
void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rank[a] < rank[b])
            swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b])
            rank[a]++;
    }
}
*/ 
ll power(ll base, ll exp) 
{ll res=1;while(exp>0) {if(exp%2==1) res=(res*base);base=(base*base);exp/=2;}return res;}
 
ll mod(ll a, ll b) {return (a % b + b) % b;}
 
ll powerm(ll base,ll exp,ll mod) 
{ll ans=1;while(exp){if(exp&1) ans=(ans*base)%mod;exp>>=1,base=(base*base)%mod;}return ans;}
 
using namespace std;

int main()
{
	fast;
	string s; cin>>s; ll k; cin>>k;
	vector<string>ans; ll n = s.size();
	unordered_map<string,ll>mp;
	for(ll i = 0; i < n; i++)
	{
		for(ll len = 1; len <= k; len++)
		{
			string t = s.substr(i,len);
			if(!mp.count(t))
				ans.push_back(t);
			mp[t]++;
		}	
	}
	std::nth_element(ans.begin(),ans.begin()+k-1,ans.end());
	cout << ans[k-1] << endl;
	return 0;
}