#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
#define all(x) x.begin(),x.end()
#define rep(i,j,n) for (int i = j; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
#define MOD 1000000007
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
//name[i][j]-> vvl name(i,vl(j))
//map<int,int>mp
//余りを切り上げる =>  (a + b - 1) / b 

signed main(){
	int n; cin>>n;
	string s; cin>>s;
	ll ans=0;
	rep(i,0,n-1){
		string a,b;
		rep(j,0,n){
			if(j<=i) a.push_back(s[j]);
			else b.push_back(s[j]);
		}
		//cout<<a<<" "<<b<<endl;
		ll cnt=0;
		map<char,int> mp;
		rep(k,0,a.size()) mp[a[k]]++;
		//cout<<mp['a']<<endl;
		set<char> st;
		rep(l,0,b.size()){
			if(mp[b[l]]>0 && !st.count(b[l])){
				cnt++;
				st.insert(b[l]);
			}
		}
		//cout<<cnt<<endl;
		ans=max(ans,cnt);
	}
	cout<<ans;
	
	return 0;
}