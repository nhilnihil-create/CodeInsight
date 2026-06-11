#include <bits/stdc++.h>
 
using namespace std;
 
#define lli long long int
#define REP(i,s,l) for(lli i=s;i<l;i++)
#define MOD 1000000007
#define DEBUG 0
#define INF (1LL<<50)

signed main(){

	lli n;
	cin>>n;
	vector<lli> a(n);

 	lli num=-1;
 	lli index=-1;

	REP(i,0,n){
		cin>>a[i];
		if(num <= abs(a[i])){
			num = abs(a[i]);
			index = i;
		}
	}
	
	vector<pair<lli,lli>> v;
		
	REP(i,0,n){
		if(i==index)continue;

		a[i] += a[index];
		v.push_back(make_pair(index,i));
	}
	bool state = (a[index]>0) ? true:false;

	if(state){
		for(lli i=0;i<n-1;i++){
			a[i+1] += a[i];
			v.push_back(make_pair(i,i+1));
		}
	}
	else{
		for(lli i=n-1;i>0;i--){
			a[i-1] += a[i];
			v.push_back(make_pair(i,i-1));
		}
	}

	cout<<v.size()<<endl;
	REP(i,0,v.size()){
		cout<<v[i].first+1<<" "<<v[i].second+1<<endl;
	}

	if(DEBUG){
		REP(i,0,n){
			cout<<a[i]<<" ";
		}
		cout<<endl;
	}
	
	return 0;
}