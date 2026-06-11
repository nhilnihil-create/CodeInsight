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

//int n;
//int ans;
//string s;
signed main(){
	IO_STREAM;
	int sum_a[3]={0};
	int sum_b[3]={0};
	int c[3][3];
	rep(i,0,3){
		rep(j,0,3){
			cin>>c[i][j];
			sum_a[i]+=c[i][j];
		}
	}
	rep(j,0,3){
		rep(i,0,3){
			sum_b[j]+=c[i][j];
		}
	}
	string ans="Yes";
	if((sum_a[0]-sum_a[1])%3) ans="No";
	if((sum_a[0]-sum_a[2])%3) ans="No";
	if((sum_a[1]-sum_a[2])%3) ans="No";
	if((sum_b[0]-sum_b[1])%3) ans="No";
	if((sum_b[0]-sum_b[2])%3) ans="No";
	if((sum_b[1]-sum_b[2])%3) ans="No";
	DBG("","","","");
	cout<<ans<<endl;
	return 0;
}
