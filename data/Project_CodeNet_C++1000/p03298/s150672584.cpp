#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
typedef long long LL;
int N;
string S;
typedef pair<string,string> P;
map<P,LL>m;
int main(){
	cin>>N>>S;
	REP(i,1<<N){
		string a="";
		string b="";
		REP(j,N){
			if((i>>j)&1){
				a.push_back(S[j]);
			}else{
				b.push_back(S[j]);
			}
		}
		P c=P(a,b);
		m[c]++;
	}
	LL ans=0;
	REP(i,1<<N){
		string a="";
		string b="";
		REP(j,N){
			if((i>>j)&1){
				a.push_back(S[N+j]);
			}else{
				b.push_back(S[N+j]);
			}
		}
		reverse(a.begin(),a.end());
		reverse(b.begin(),b.end());
		P c=P(a,b);
		ans+=m[c];
	}
	cout<<ans<<endl;
}