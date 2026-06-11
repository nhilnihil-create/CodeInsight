#include<bits/stdc++.h>
using namespace std;
bool ip(long long n){
	if(n==1) return false;
	for(long long i=2;i*i<=n;i++)
	if(n%i==0)
	return false;
	return true;
}
int main(){
	int q;
	cin>>q;
	vector<int> l(q),r(q);
	for(int i=0;i<q;i++) cin>>l[i]>>r[i];
	vector<int> pv(100000);
	for(int i=3;i<=100000;i++)
		if(ip(i) && ip((i+1)/2)) ++pv[i];
	for(int i=3;i<=100000;i++)
	pv[i]+=pv[i-2];
	for(int i=0;i<q;i++)
	if(l[i]==1)
	cout<<pv[r[i]]<<endl;
	else
	cout<<pv[r[i]]-pv[l[i]-2]<<endl;
}