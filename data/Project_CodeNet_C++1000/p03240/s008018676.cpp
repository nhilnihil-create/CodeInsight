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

class Data{
public:
	ll x,y,h;
};

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout<<fixed<<setprecision(10);

	int N=in();
	vector<Data> P(N);
	REP(i,N){
		P[i].x=in();
		P[i].y=in();
		P[i].h=in();
	}

	REP(i,101){
		int cy=i;
		REP(j,101){
			int cx=j;
			int H = -1;
			bool exist=true;
			REP(k,N){
				if(P[k].h>=1){
					H=P[k].h+abs(P[k].x-cx)+abs(P[k].y-cy);
					break;
				}
			}
			REP(k,N){
				int V=max<ll>(H-abs(P[k].x-cx)-abs(P[k].y-cy),0);
				if(P[k].h!=V){
					exist = false;
					break;
				}
			}
			if(exist){
				out(cx,cy,H);
				return 0;
			}
		}
	}
	return 0;
}
