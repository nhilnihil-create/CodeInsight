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

	int H=in(),W=in();
	vector<vector<int>> M(H,vector<int>(W,1<<30));
	queue<int> Q;
	REP(i,H){
		string S=in<string>();
		REP(j,W){
			if(S[j]=='#'){
				M[i][j]=0;
				Q.push(j+i*W);
			}
		}
	}
	while(!Q.empty()){
		int V=Q.front();
		Q.pop();
		int u=V%W,v=V/W;
		if(u>0 && M[v][u]+1<M[v][u-1]){
			M[v][u-1] = M[v][u]+1;
			Q.push(u-1+v*W);
		}
		if(u<W-1 && M[v][u]+1<M[v][u+1]){
			M[v][u+1] = M[v][u]+1;
			Q.push(u+1+v*W);
		}
		if(v>0 && M[v][u]+1<M[v-1][u]){
			M[v-1][u] = M[v][u]+1;
			Q.push(u+(v-1)*W);
		}
		if(v<H-1 && M[v][u]+1<M[v+1][u]){
			M[v+1][u] = M[v][u]+1;
			Q.push(u+(v+1)*W);
		}
	}
	int maxV=0;
	REP(i,H){
		REP(j,W){
			maxV=max(maxV,M[i][j]);
		}
	}
	out(maxV);
	return 0;
}
