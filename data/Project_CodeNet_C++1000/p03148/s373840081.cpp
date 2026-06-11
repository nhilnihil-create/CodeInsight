#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n,m;
	cin>>n>>m;
	vector<pair<long long,long long> > a(n);
	for(int i=0;i<n;i++){
		cin>>a[i].second>>a[i].first;
		a[i].second--; 
	}
	sort(a.rbegin(),a.rend());
	long long s=0;
	long long c=0;
	priority_queue<pair<long long,long long> > k;
	vector<long long> f(n);
	for(int i=0;i<m;i++){
		s+=a[i].first;
		if(f[a[i].second]==0) c++;
		else k.push(make_pair(-a[i].first,a[i].second));
		f[a[i].second]++;
	}
	s+=c*c;
	vector<long long> x;
	x.push_back(s);
	long long i=m;
	while(i<n && !k.empty()){
		if(f[a[i].second]!=0){
			i++;
			continue;
		}
		s-=c*c;
		s+=k.top().first;
		k.pop();c++;
		s+=c*c;s+=a[i].first;
		f[a[i].second]=1;
		x.push_back(s);
		i++;
	}
	sort(x.rbegin(),x.rend());
	cout<<x[0];
}