#include <bits/stdc++.h>
#define ll long long
#define f(i, a, b) for(ll i = a; i <= b; ++i)
#define ff(i, a, b) for(ll i = a; i < b; ++i)
#define F(i, a, b) for(ll i = a; i >= b; --i)
#define FF(i, a, b) for(ll i = a; i > b; --i)
#define x first
#define y second
#define X real()
#define Y imag()
using namespace std;
typedef complex<ll> P;
typedef pair<ll, ll> ii;
typedef tuple<ll, ll, ll> iii;

string s;
ll l, r;
vector<ll> ans;
vector<ii> arr;

signed main(){
//	freopen("PERFECT1.inp","r",stdin);
//	freopen("PERFECT1.out","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> s;
	if(s.back() != '0') cout <<"-1";
	else{
		l = 0; r = s.size()-2;
		while(l <= r){
			if(s[l] != s[r] || (l == 0 && r == s.size()-2 && (s[l] == '0' || s[r] == '0'))){
				cout <<"-1";
				return 0;
			}
			if(s[l] == '1' && s[r] == '1') ans.push_back(l+1);
			l++, r--;
		}
		ll dist, prev = 1, node = 1;
		for(auto i : ans){
			dist = i-prev; prev = i;
			ff(j,0,dist) arr.push_back({node+j, node+dist});
			node += dist;
		}
		arr.push_back({node, node+1});
		node++;
		f(i,node+1,s.size()){
			arr.push_back({node, i});
		}
		for(auto i : arr) cout << i.x <<" "<<i.y<<"\n";
	}
}

