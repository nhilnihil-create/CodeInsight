#include "bits/stdc++.h"

#define REP(i,num) for(int i=0;i<(num);++i)
#define LOOP(i) while(i--)
#define ALL(c) c.begin(),c.end()
#define PRINTALL(c) for(auto pitr=c.begin();pitr!=c.end();++pitr){cout<<*pitr;if(next(pitr,1)!=c.end())cout<<' ';}cout<<endl;
#define PAIRCOMP(c,comp) [](const pair<ll,ll>& lhs,const pair<ll,ll>& rhs){return lhs.c comp rhs.c;}

using namespace std;
using ll = long long;

constexpr ll atcoder_mod = 1e9+7;

template<typename T=int>
T in(){T x; cin >> x; return (x);}
template<typename T=int,typename C=vector<T>>
C vecin(int N){C x(N);REP(i,N){x[i]=in<T>();}return move(x);}

void vout(){cout << endl;}
template<typename Head,typename... Tail>
void vout(Head&& h,Tail&&... t){cout << ' ' << h;vout(forward<Tail>(t)...);}
void out(){cout << endl;}
template<typename Head,typename... Tail>
void out(Head&& h,Tail&&... t){cout << h;vout(forward<Tail>(t)...);}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout<<fixed<<setprecision(10);

	int N=in(),K=in();
	auto V=vecin<ll>(N);
	vector<ll> S(N+1,0),B(N*(N+1)/2,0);
	REP(i,N){
		S[i+1]=S[i]+V[i];
	}
	for(int i=1,index=0;i<=N;i++){
		for(int j=i;j<=N;j++){
			B[index++] = S[j]-S[i-1];
		}
	}
	sort(ALL(B),greater<ll>());
	int M=0;
	for(ll i=B[0];i;i>>=1LL){
		M++;
	}
	ll A=0;
	REP(i,M){
		ll Q=1LL<<(M-1-i);
		ll sum=0;
		REP(j,N*(N+1)/2){
			if(((A+Q)&B[j])==(A+Q)) sum++;
		}
		if(sum>=K) A+=Q;
	}
	out(A);
	return 0;
}