#include "bits/stdc++.h"

#define REP(i,num) for(ll i=0;i<(num);++i)
#define FOR(i,c,num) for(ll (i)=(c);(i)<(num);++(i))
#define LOOP(i) while(i--)
#define ALL(c) c.begin(),c.end()
#define PRINTALL(c) for(auto pitr=c.begin();pitr!=c.end();++pitr){cout<<*pitr;if(next(pitr,1)!=c.end())cout<<' ';}cout<<endl;
#define PAIRCOMP(c,comp) [](const pair<ll,ll>& lhs,const pair<ll,ll>& rhs){return lhs.c comp rhs.c;}

using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;

constexpr ll atcoder_mod = 1e9+7;

template<typename T=ll>
T in(){T x; cin >> x; return (x);}
template<typename T=ll,typename C=vector<T>>
C vecin(int N){C x(N);REP(i,N){x[i]=in<T>();}return move(x);}

void vout(){cout << endl;}
template<typename Head,typename... Tail>
void vout(Head&& h,Tail&&... t){cout << ' ' << h;vout(forward<Tail>(t)...);}
void out(){cout << endl;}
template<typename Head,typename... Tail>
void out(Head&& h,Tail&&... t){cout << h;vout(forward<Tail>(t)...);}

template<typename T>
bool chmax(T& a,T b){if(a<b){a=b;return true;}return false;}
template<typename T>
bool chmin(T& a,T b){if(a>b){a=b;return true;}return false;}

#define EXACT 0
#define SMALLER 1

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout<<fixed<<setprecision(10);

	auto N=in(),M=in();
	vll A=vecin(N);
	vll B(60,0),C(60,0);
	REP(i,N){
		ll V=A[i],index=0;
		while(V){
			if(V&1ll){
				B[index]++;
			}
			index++;
			V/=2ll;
		}
	}
	ll V=M,index=0;
	while(V){
		if(V&1ll){
			C[index]++;
		}
		index++;
		V/=2ll;
	}
	reverse(ALL(B));
	reverse(ALL(C));

	vvll dp(61,vll(2,-(1ll<<60)));
	dp[0][0]=0;
	REP(i,60){
		ll cost_zero = B[i];
		ll cost_one = N-B[i];
		if(C[i]){
			chmax(dp[i+1][EXACT],dp[i][EXACT]*2ll+cost_one);
			chmax(dp[i+1][SMALLER],dp[i][EXACT]*2ll+cost_zero);
			chmax(dp[i+1][SMALLER],dp[i][SMALLER]*2ll+cost_one);
			chmax(dp[i+1][SMALLER],dp[i][SMALLER]*2ll+cost_zero);
		}
		else{
			chmax(dp[i+1][EXACT],dp[i][EXACT]*2ll+cost_zero);
			chmax(dp[i+1][SMALLER],dp[i][SMALLER]*2ll+cost_one);
			chmax(dp[i+1][SMALLER],dp[i][SMALLER]*2ll+cost_zero);
		}
	}
	out(max(dp[60][0],dp[60][1]));
	return 0;
}
