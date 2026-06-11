#include "bits/stdc++.h"

#define REP(i,num) for(ll i=0;i<(num);++i)
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

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout<<fixed<<setprecision(10);

	int N=in(),C=in();
	vvll CM(C,vll(C));
	REP(i,C){
		REP(j,C) CM[i][j]=in();
	}
	vvll D(3),CD(3,vll(C,0));
	REP(i,N){
		REP(j,N){
			D[(i+j)%3].push_back(in()-1);
		}
	}

	REP(i,3){
		REP(j,C){
			for(auto& x:D[i]){
				CD[i][j] += CM[x][j];
			}
		}
	}

	ll minS=1ll<<60;
	REP(i,C){
		REP(j,C){
			if(i==j) continue;
			REP(k,C){
				if(i==k || j==k) continue;
				minS = min(minS,CD[0][i]+CD[1][j]+CD[2][k]);
			}
		}
	}
	
	out(minS);
	return 0;
}
