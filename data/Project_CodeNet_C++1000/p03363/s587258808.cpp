#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll=long long;

int main() {
	int n;
	cin>>n;
	vector<ll> A(n);
	rep(i,n)cin>>A[i];
	//累積和
	vector<ll> s(n+1,0);
	rep(i,n)s[i+1]=s[i]+A[i];
	
	//sort(s.begin(),s.end());
	
	map<ll,ll> hindo;
	rep(i,n+1){
		if(hindo.count(s[i]))hindo[s[i]]++;
		else hindo[s[i]]=1;
	}
	
	ll sum=0;
	for(auto p:hindo){
		ll n=p.second;
		sum+=n*(n-1)/2;
	}
	
	cout<<sum<<endl;
}

//RE