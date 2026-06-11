#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<n;i++)
#define rev(i,n) for(int i=n-1;i>=0;i--)
#define all(v) v.begin(),v.end()
#define P pair<int,int>
#define len(s) (int)s.size()
#define pb push_back

template<class T> inline bool chmin(T &a, T b){
	if(a>b){a=b;return true;}
	return false;
}
template<class T> inline bool chmax(T &a, T b){
	if(a<b){a=b;return true;}
	return false;
}
constexpr int mod = 1e9+7;
constexpr int inf = 3e18;

signed main(){
	string s;cin>>s;
	if(len(s)!=26){
		set<char>st;for(auto i:s)st.insert(i);
		for(char i='a';i<='z';i++){
			if(st.find(i)==st.end()){
				cout<<s<<i<<endl;return 0;
			}
		}
	}
	set<char>st;st.insert(s.back());
	for(int i=24;i>=0;i--){
		if(s[i]<s[i+1]){
			cout<<s.substr(0,i)<<*st.lower_bound(s[i])<<endl;
			return 0;
		}
		st.insert(s[i]);
	}
	cout<<-1<<endl;
}
