#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define fi first
#define se second
#define pb push_back
#define rep(i, s, n) for (int i = s; i < n; i++)
#define rrep(i, s, n) for (int i = (n)-1; i >= (s); i--)
#define all(a) a.begin(),a.end()
typedef pair<int,int>pint;
typedef vector<int>vint;
typedef vector<pint>vpint;
const long long MOD = 1000000007, INF = 1e17;
 
#define endl '\n'
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0)
 
template<class T>inline bool chmax(T& a,T b){if(a<b){a=b;return true;}return false;}
template<class T>inline bool chmin(T& a,T b){if(a>b){a=b;return true;}return false;}
 
template<typename T>vector<T>
make_v(size_t a){return vector<T>(a);}
template<typename T,typename... Ts>
auto make_v(size_t a,Ts... ts){
	return vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));
}
template<typename T,typename V>
typename enable_if<is_class<T>::value==0>::type
fill_v(T &t,const V &v){t=v;}
template<typename T,typename V>
typename enable_if<is_class<T>::value!=0>::type
fill_v(T &t,const V &v){
	for(auto &e:t) fill_v(e,v);
}
void pv(vector<int>&v){
	for(int i = 0;i<v.size();i++){
		if(i)cout<<' ';
		cout<<v[i];
	}
	cout<<endl;
}

signed main()
{
	IOS();
	int N;
	cin>>N;
	int sz = 0;
	vector<pair<int,int>>g[20];
	vector<int>cnt(19,0);
	int n = N,tmp = 0,flg=0,ma = -1,now = 0;
	while(n){
		if(n&1){cnt[tmp]++;flg++;ma = tmp;}
		n /= 2;
		tmp++;
		
		if(tmp == 19 && n){
			ma = 19;
			now = (1ll << 19);
			n = 0;
		}
		//cout<<tmp<<" "<<n<<endl;
	}
	/*
	if(flg==tmp){
		rrep(i,0,19){
			if(cnt[i]){
				g[i].push_back({i+1,1ll<<i});
				sz++;
			}
			g[i].push_back({i+1,0});
			sz++;
		}
		cout<<20<<" "<<sz<<endl;
		rep(i,0,20){
			for(auto e:g[i]){
				cout<<i+1<<" "<<e.fi+1<<" "<<e.se<<endl;
			}
		}
		return 0;
	}*/
	int co = flg;
	int t = N - (1ll << (ma));
	rrep(i,0,19){
		//cout<<i<<" "<<cnt[i]<<endl;
		if(ma <= i){
			g[19-(i+1)].push_back({19-i,0});
			sz++;
		}else{
			g[19-(i+1)].push_back({19-i,1ll<<i});
			g[19-(i+1)].push_back({19-i,0});
			sz+=2;
		}
		//cout<<t<<" "<<(1ll << i)<<endl;
		if(t>=(1ll << i)){
			g[0].push_back({19-i,now});
			sz++;
			t -= (1ll << i);
		}
		if(cnt[i])now |= (1ll << i);
		//cout<<sz<<endl;
	}
	cout<<20<<" "<<sz<<endl;
	rep(i,0,20){
		for(auto e:g[i]){
			cout<<i+1<<" "<<e.fi+1<<" "<<e.se<<endl;
		}
	}
}