#include<bits/stdc++.h>
using namespace std;
using ll  = long long;
using vl  = vector<ll>;
using vi  = vector<int>;
#define _GLIBCXX_DEBUG
#define IO_STREAM cin.tie(0);ios::sync_with_stdio(false)
#define all(x) x.begin(),x.end()
#define rep(i,sta,end) for(ll i=sta;i<end;++i)
#define lcm(a,b) (a)/__gcd((a),(b))*(b)
#define pb push_back
const ll MOD = 1000000007;
const double PI = acos(-1);
//or-> ||
#define DBG(a,b,c,d) //cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<endl

signed main(){
	IO_STREAM;
	ll N;
	ll ans;
	string s;
	cin>>N;
	map<char,ll>cnt;
	rep(i,0,N){
		cin>>s;
		if(s[0]=='M'){
			cnt[s[0]]++;
		}
		else if(s[0]=='A'){
			cnt[s[0]]++;
		}
		else if(s[0]=='R'){
			cnt[s[0]]++;
		}
		else if(s[0]=='C'){
			cnt[s[0]]++;
		}
		else if(s[0]=='H'){
			cnt[s[0]]++;
		}
	}
	ans=0;
	ans+=cnt['M']*cnt['A']*cnt['R'];
	ans+=cnt['M']*cnt['A']*cnt['C'];
	ans+=cnt['M']*cnt['A']*cnt['H'];
	ans+=cnt['M']*cnt['R']*cnt['C'];
	ans+=cnt['M']*cnt['R']*cnt['H'];
	ans+=cnt['M']*cnt['C']*cnt['H'];
	ans+=cnt['A']*cnt['R']*cnt['C'];
	ans+=cnt['A']*cnt['R']*cnt['H'];
	ans+=cnt['A']*cnt['C']*cnt['H'];
	ans+=cnt['R']*cnt['C']*cnt['H'];
	DBG("","","","");
	cout<<ans<<endl;
	return 0;
}
