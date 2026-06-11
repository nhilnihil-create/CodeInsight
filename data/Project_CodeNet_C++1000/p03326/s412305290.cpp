#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n,m;
	cin>>n>>m;
	vector<long long> a(n),b(n),c(n),d(n);
	for(int i=0;i<n;i++){
		long long x,y,z;
		cin>>x>>y>>z;
		a[i]=x+y+z;
		b[i]=x+y-z;
		c[i]=x-y+z;
		d[i]=x-z-y; 
	}
	sort(a.begin(),a.end());sort(b.begin(),b.end());
	sort(c.begin(),c.end());sort(d.begin(),d.end());
	vector<long long> s(8);
	for(int i=0;i<m;i++){
		s[0]-=a[i];s[1]-=b[i];
		s[2]-=c[i];s[3]-=d[i];
		s[4]+=a[n-1-i];s[5]+=b[n-1-i];
		s[6]+=c[n-1-i];s[7]+=b[n-1-i];
	}
	sort(s.begin(),s.end());
	cout<<s[7];
}