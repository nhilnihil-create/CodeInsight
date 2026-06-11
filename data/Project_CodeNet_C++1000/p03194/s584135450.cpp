#include<bits/stdc++.h>
using namespace std;
long long n,p;
map<long long,long long> f;
map<long long,long long>::iterator it;
void get() {
	long long temp=p;
	for(long long i=2;i*i<=p;i++) {
		if(temp==1) break;
		if(temp%i==0) {
			while(temp%i==0) {
				temp/=i;
				f[i]++;
			}
		}
	} 
}
int main() {
	cin>>n>>p;
	get();
	long long cnt=1;
	if(n==1) {
		cout<<p;
		exit(0);
	}
	for(it=f.begin();it!=f.end();it++) {
		while(it->second>=n) {
			cnt*=it->first;
			it->second-=n; 
		}
	}
	cout<<cnt;
	return 0;
}