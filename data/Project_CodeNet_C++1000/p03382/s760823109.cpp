#include <bits/stdc++.h>
typedef long long ll;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,a) FOR(i,0,a)
	
using namespace std;
const int MAX_N=1e5;
int n,a[MAX_N];
int dis(int x,int y){
	if (y&1){
		return min(abs(y/2-x),abs(y/2+1-x));
	}else{
		return abs(y/2-x);
	}
}

int main(){
	cin>>n;
	REP(i,n){
		cin>>a[i];
	}
	sort(a,a+n);
	int ma=0;
	REP(i,n-2){
		if (dis(a[i+1],a[n-1])<dis(a[ma],a[n-1])){
			ma=i+1;
		}
	}
	cout<<a[n-1]<<" "<<a[ma]<<endl;
	return 0;
}