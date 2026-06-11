#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define mp make_pair
#define inf 1000000007
using namespace std;
set<double> lms[40009]; //idx*0.5sec 
void setadd(int lef, int rig, int lim, int n,int sum){
	double dlef = 1.0 * lef;
	double drig = 1.0 * rig;
	for(int i=0;i<=2*sum;i++){
		double ct = 0.5 * i;
		if(ct < dlef){
			lms[i].insert(lim+(dlef-ct));
		}
		else if(drig<ct){
			lms[i].insert(lim+(ct-drig));
		}
		else{
			lms[i].insert(lim);
		}
	}
}
signed main(){
	int n;
	cin>>n;
	vector<int> t,x;
	int sum = 0;
	for(int i=0;i<n;i++){
		int tt;
		cin>>tt;
		t.pb(tt);
		sum+=tt;
	}
	for(int i=0;i<n;i++){
		int tx;
		cin>>tx;
		x.pb(tx);
	}
	int cur = 0;
	setadd(0,0,0,n,sum);
	for(int i=0;i<n;i++){
		setadd(cur,cur+t[i],x[i],n,sum);
		cur += t[i];
	}
	setadd(cur,cur,0,n,sum);
	vector<double> flim;
	for(int i=0;i<=2*sum;i++){
		flim.pb(  *(lms[i].upper_bound(-1)) );
	}
	double ans=0;
	for(int i=0;i<2*sum;i++){
		ans += 0.25*(flim[i]+flim[i+1]);
	}
	cout<<setprecision(12)<<ans<<endl;
	return 0;
}