#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	double n,a,sum=0;
	cin>>n;
	vector<double>v(n);
	for(int i=0;i<n;i++){
		cin>>v[i];
		sum+=v[i];
	}
	a=sum/n;
	double mi=10000,ans=-1;
	for(int i=0;i<n;i++){
		if(abs(v[i]-a)<mi){
			mi=abs(v[i]-a);
			ans=i;
		}
	}
	cout<<ans<<endl;
	return 0;
}
