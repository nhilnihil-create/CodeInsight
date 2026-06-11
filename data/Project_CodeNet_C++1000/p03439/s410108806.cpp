#include "bits/stdc++.h"

#define REP(i,num) for(int i=0;i<(num);++i)
#define ALL(c) c.begin(),c.end()
#define LOOP(i) while(i--)
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

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout<<fixed<<setprecision(10);

	ll N=in();
	ll left=0,right=N,mid=0;
	ll leftS=0,rightS=0,midS=0;
	string S;
	auto func = [&](ll query,ll& sex){
		cout.flush();
		out(query);
		S=in<string>();
		if(S=="Vacant") exit(0);
		sex = S=="Male"?1:0;
	};
	func(left,leftS);
	rightS=leftS;
	REP(i,16){
		mid = (left+right)/2;
		func(mid,midS);
		
		if((left-mid)%2){
			if(leftS==midS){
				right = mid;
				rightS = midS;
			}
			else{
				left = mid;
				leftS = midS;
			}
		}
		else{
			if(leftS!=midS){
				right = mid;
				rightS = midS;
			}
			else{
				left = mid;
				leftS = midS;
			}
		}
	}
	for (int m=left+1; m<right; ++m) {
		func(m,leftS);
	}
	return 0;
}
