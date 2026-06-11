#include "bits/stdc++.h"

#define REP(i,num) for(int i=0;i<(num);++i)
#define LOOP(i) while(i--)
#define ALL(c) c.begin(),c.end()
#define PRINTALL(c) for(auto& x:c){cout<<x<<' ';}cout<<endl;
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

class Data{
public:
	ll first,second,third;
	Data()=default;
	Data(ll f,ll s,ll t):first(f),second(s),third(t){}
};

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout<<fixed<<setprecision(10);

	int N=in();
	vector<ll> F(N);
	ll sumT=0,sumA=0;
	REP(i,N){
		ll t=in(),a=in();
		F[i] = t+a;
		sumA += a;
	}
	sort(ALL(F),greater<ll>());
	for(int i=0;i<N;i+=2){
		sumT += F[i];
	}
	
	out(sumT-sumA);
	return 0;
}
