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

	int N=in();
	vector<vector<int>> F(N,vector<int>(10)),C(N,vector<int>(11));
	REP(i,N){
		REP(j,10){
			F[i][j]=in();
		}
	}
	REP(i,N){
		REP(j,11){
			C[i][j]=in();
		}
	}
	int maxC=-(1<<30);
	for(int i=1;i<=1023;i++){
		array<int,10> A{0,0,0,0,0,0,0,0,0,0};
		int V=i,index=0;
		while(V){
			if(V&1) A[index]=1;
			index++;
			V/=2;
		}

		int sumC=0;
		REP(j,N){
			int sum=0;
			REP(k,10){
				if(A[k]==1 && F[j][k]==1) sum++; 
			}
			sumC += C[j][sum];
		}
		maxC = max(maxC,sumC);
	}
	out(maxC);
	return 0;
}
