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

	vector<ll> Neg,Pos;
	REP(i,N){
		ll V=in();
		if(V<0) Neg.push_back(-V);
		else if(V>0) Pos.push_back(V);
		else K--;
	}
	sort(ALL(Neg));

	ll minD=1LL<<60;
	int NS=Neg.size(),PS=Pos.size();
	int NN=min(NS,K),PN=K-NN;
	while(NN>=0 && PN<=PS){
		ll ND = NN>0? Neg[NN-1]:0;
		ll PD = PN>0? Pos[PN-1]:0;
		minD = min({minD,2LL*ND+PD,ND+2LL*PD});
		NN--;
		PN++;
	}
	
	out(minD);
	return 0;
}
