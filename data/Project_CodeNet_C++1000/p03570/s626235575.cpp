#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<n;i++)
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

string s;
map<int,int>mp;
map<int,bool>used;
signed main(){
	cin>>s;
	int now=0;
	used[0]=true;
	rep(i,len(s)){
		now^=1<<(s[i]-'a');
		if(i==len(s)-1){
			if(used[now])mp[now]++;
		}
		rep(j,26){
			if(used[now^(1<<j)]){
				if(!used[now]){
					used[now]=true;
					mp[now]=mp[now^(1<<j)]+1;
				}else {
					chmin(mp[now],mp[now^(1<<j)]+1);
				}
			}
		}
	}
	cout<<mp[now]<<endl;
}
