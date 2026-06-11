#include <bits/stdc++.h>
using namespace std;

int main() {
	long n,m,i,j,ans,cur;
	cin >> n >> m;
	vector<long> a(n);
	for(i=0; i<n; i++){
		cin >> a[i];
	}
	map<long,long> p;
	
	p[0]=1;
	cur=0; ans=0;
	for(i=0; i<n; i++){
		cur=(cur+a[i])%m;
		if(p[cur]==0){
			p[cur]=1;
		}else{
			ans+=p[cur];
			p[cur]++;
		}
	}
	cout << ans << endl;
	return 0;
}
