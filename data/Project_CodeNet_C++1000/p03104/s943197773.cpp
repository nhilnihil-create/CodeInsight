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

	ll A=in<ll>(),B=in<ll>();
	if(B%2LL){
		ll N=(B+1LL)/2LL;
		if(N%2LL) B=1;
		else B=0;
	}
	else{
		ll N=(B)/2LL;
		if(N%2LL) B^=1LL;
		else B^=0LL;
	}
	A = max(A-1LL,0LL);
	if(A%2LL){
		ll N=(A+1LL)/2LL;
		if(N%2LL) A=1;
		else A=0;
	}
	else{
		ll N=(A)/2LL;
		if(N%2LL) A^=1LL;
		else A^=0LL;
	}

	out(A^B);
	return 0;
}
