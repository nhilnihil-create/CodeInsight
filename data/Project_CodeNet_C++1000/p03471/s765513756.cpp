#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define REP(i,s,n) for(int i=s;i<n;i++)
#define NUM 2520
#define INF (1LL<<50)
#define DEBUG 0
#define mp(a,b) make_pair(a,b)
#define SORT(V) sort(V.begin(),V.end())
#define PI (3.141592653589794)
#define TO_STRING(VariableName) # VariableName
#define LOG(x) if(DEBUG)cout<<TO_STRING(x)<<"="<<x<<" ";
#define LOGE if(DEBUG)cout<<endl;

template<class T>bool chmax(T & a, const T & b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }


int main(){

	lli N,Y;
	cin>>N>>Y;

	REP(x,0,N+1){
		REP(y,0,N-x+1){
			lli z = N-x-y;
			if(z<0)continue;
			if(10000*x+5000*y+1000*z == Y){
				cout<<x<<" "<<y<<" "<<z<<endl;
				return 0;
			}
		}
	}

	cout<<"-1 -1 -1"<<endl;


    return 0;
}
