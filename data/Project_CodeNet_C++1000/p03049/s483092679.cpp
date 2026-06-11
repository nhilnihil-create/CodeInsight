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

int count_substr(const string& word,const string& q) {
	int count = 0;
	for (string::size_type pos = 0; (pos = word.find(q, pos)) != string::npos; pos += q.size()) {
		++count;
	}
	return count;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout<<fixed<<setprecision(10);
	
	int N=in();
	vector<string> S=vecin<string>(N);

	int startB=0,endA=0,both=0,AB=0;
	REP(i,N){
		if(S[i].front()=='B' && S[i].back()=='A') both++;
		else if(S[i].front()=='B') startB++;
		else if(S[i].back()=='A') endA++;

		AB += count_substr(S[i],"AB");
	}

	if(!startB && !endA){
		AB += max(both-1,0);
	}
	else{
		int minAB = min(startB,endA);
		startB -= minAB;
		endA -= minAB;
		AB += minAB;
		if(!startB){
			int rest = min(endA,both);
			both -= rest;
			AB += rest;
			AB += both;
		}
		else{
			int rest = min(startB,both);
			both -= rest;
			AB += rest;
			AB += both;
		}
	}
	out(AB);
	return 0;
}
