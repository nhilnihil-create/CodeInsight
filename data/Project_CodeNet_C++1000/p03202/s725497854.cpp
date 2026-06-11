#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pb push_back
#define rep(i, s, n) for (int i = s; i < n; i++)
#define rrep(i, s, n) for (int i = (n)-1; i >= (s); i--)
#define all(a) a.begin(),a.end()
typedef pair<int,int>pint;
typedef vector<int>vint;
typedef vector<pint>vpint;
const long long MOD = 1000000007, INF = 1e18;
template<class T>inline bool chmax(T& a,T b){if(a<b){a=b;return true;}return false;}
template<class T>inline bool chmin(T& a,T b){if(a>b){a=b;return true;}return false;}
string get_str(string s) {
	s+=',';
	string ret="";
	for(int i=0; i<s.size(); i++) {
		if(s[i]==',') ret+="=%ld, ";
		else ret+=s[i];
	}
	return ret;
}
#define dump(...) printf(get_str(#__VA_ARGS__).c_str(),__VA_ARGS__);cout<<endl
 
#define endl '\n'
#define IOS()                     \
	ios_base::sync_with_stdio(0); \
	cin.tie(0)
 
//******************************************************************************
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

int N;

bool f(int n,vint&a){
	vector<pair<int,int>>vec;
	int now = 0;
	rep(i,0,N){
		if(now<a[i])vec.push_back({0ll,a[i]-now});
		else{
			int t = now-a[i];
			int sz = vec.size();
			rrep(j,0,sz){
				auto tmp = vec.back();
				vec.pop_back();
				if(t >= tmp.se){
					t -= tmp.se;
				}else{
					vec.push_back({tmp.fi,tmp.se-t});
					break;
				}
			}
			sz = vec.size();
			vpint Vpush;
			rrep(j,0,sz){
				auto tmp = vec[j];
				vec.pop_back();
				if(j==0&&tmp.fi==n-1)return false;
				if(tmp.fi<n-1){
					if(tmp.se>1)vec.push_back({tmp.fi,tmp.se-1});
					vec.push_back({tmp.fi+1,1});
					break;
				}else{
					Vpush.push_back({0ll,tmp.se});
				}
			}
			rrep(j,0,Vpush.size()){
				vec.push_back(Vpush[j]);
			}
		}
		now = a[i];
	}
	return true;
}

signed main()
{
	//IOS();
	cin>>N;
	vint a(N);
	for(int i = 0;i < N;i++){
		cin>>a[i];
	}
	int l = 0, r = 1e18 + 1;
    while(r - l > 1){
        int c = (l + r) / 2;
        if(f(c,a)) r = c;
        else l = c;
    }
    cout << r << endl;
}