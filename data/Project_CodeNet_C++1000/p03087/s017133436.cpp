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
#define INF 1000000000000000LL
const ll MOD = 1000000007;
const double PI = acos(-1);
//||
#define DBG(a,b,c,d) //cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<endl
//DBG("","","","");

signed main(){
	IO_STREAM;
	int N,Q;
	cin>>N>>Q;
	string S;
	cin>>S;
	vi l(Q),r(Q);
	rep(i,0,Q){
		cin>>l[i]>>r[i];
		l[i]--;r[i]--;
	}
	vi total(N);
	if(S[0]=='A' && S[1]=='C') total[0]=1;
	rep(i,1,N){
		if(S[i-1]=='A' && S[i]=='C'){
			total[i]=total[i-1]+1;
		}
		else{
			total[i]=total[i-1];
		}
	}

	rep(i,0,Q){
		cout<<total[r[i]]-total[l[i]]<<endl;
	}
	return 0;
}
