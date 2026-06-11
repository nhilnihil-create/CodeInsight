#include <bits/stdc++.h>
typedef long long ll;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,a) FOR(i,0,a)
	
using namespace std;

const int MAX_N=1e5;
int N,M;
typedef pair<int,int> P;
int v2g[MAX_N];
map<int,int> g2v[MAX_N];

int main(){
	cin>>N>>M;
	REP(i,N){
		v2g[i]=i;
		g2v[i].insert(P(i,0));
	}
	bool ans=true;
	REP(i,M){
		int L,R,D;
		cin>>L>>R>>D;
		L--;
		R--;
		if (v2g[L]==v2g[R]){
			int g=v2g[L];
			if (g2v[g][R]-g2v[g][L]!=D){
				ans=false;
			}
		}else{
			int f,t,d;
			if (g2v[v2g[L]].size()<g2v[v2g[R]].size()){
				f=v2g[L];
				t=v2g[R];
				d=-D-g2v[f][L]+g2v[t][R];
			}else{
				f=v2g[R];
				t=v2g[L];
				d=D-g2v[f][R]+g2v[t][L];
			}
			for(auto i:g2v[f]){
				g2v[t][i.first]=i.second+d;
				v2g[i.first]=t;
			}
		}
	}
	cout<<(ans ? "Yes" : "No")<<endl;
	return 0;
}