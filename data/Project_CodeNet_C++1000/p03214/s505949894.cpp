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

	lli n;
	cin>>n;

	vector<lli> a(n);
	lli sum=0;
	REP(i,0,n){
		cin>>a[i];
		sum += a[i];
		a[i]*=n;
	}

	lli ans=INF;
	lli ansI = -1;

	REP(i,0,n){
		if(ans>abs(sum-a[i])){
			ans = abs(sum-a[i]);
			ansI=i;
		}
	}

	cout<<ansI<<endl;



    return 0;
}
