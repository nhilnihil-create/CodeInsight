#include "bits/stdc++.h"

#define REP(i,num) for(ll i=0;i<(num);++i)
#define LOOP(i) while(i--)
#define ALL(c) c.begin(),c.end()
#define PRINTALL(c) for(auto pitr=c.begin();pitr!=c.end();++pitr){cout<<*pitr;if(next(pitr,1)!=c.end())cout<<' ';}cout<<endl;
#define PAIRCOMP(c,comp) [](const pair<ll,ll>& lhs,const pair<ll,ll>& rhs){return lhs.c comp rhs.c;}

using namespace std;
using ll = long long;

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

class Data{
public:
	ll y1,x1,y2,x2;
};

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout<<fixed<<setprecision(10);

	ll H=in(),W=in();
	vector<vector<ll>> M(H,vector<ll>(W,0)),F(H,vector<ll>(W,0));
	REP(i,H){
		REP(j,W){
			M[i][j]=in();
		}
	}
	vector<Data> D;
	F[0][0]=1;
	queue<ll> Q;
	Q.push(0);
	while(!Q.empty()){
		auto x=Q.front();
		Q.pop();
		auto u=x%W,v=x/W;
		if(u<W-1 && F[v][u+1]==0){
			if(M[v][u]%2LL){
				M[v][u+1]++;
				Data d;
				d.y1=v,d.x1=u,d.y2=v,d.x2=u+1;
				D.push_back(d);
			}
			F[v][u+1]=1;
			Q.push(u+1+v*W);
		}
		else if(v<H-1 && F[v+1][u]==0){
			if(M[v][u]%2LL){
				M[v+1][u]++;
				Data d;
				d.y1=v,d.x1=u,d.y2=v+1,d.x2=u;
				D.push_back(d);
			}
			F[v+1][u]=1;
			Q.push(u+(v+1)*W);
		}
		else if(u>0 && F[v][u-1]==0){
			if(M[v][u]%2LL){
				M[v][u-1]++;
				Data d;
				d.y1=v,d.x1=u,d.y2=v,d.x2=u-1;
				D.push_back(d);
			}
			F[v][u-1]=1;
			Q.push(u-1+v*W);
		}
		else if(v>0 && F[v-1][u]==0){
			if(M[v][u]%2LL){
				M[v-1][u]++;
				Data d;
				d.y1=v,d.x1=u,d.y2=v-1,d.x2=u;
				D.push_back(d);
			}
			F[v-1][u]=1;
			Q.push(u+(v-1)*W);
		}
	}
	out(D.size());
	for(auto& x:D){
		out(x.y1+1,x.x1+1,x.y2+1,x.x2+1);
	}
	return 0;
}
