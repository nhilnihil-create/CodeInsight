#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;

const int N=2e5+5;
long long n,a[N],ANS,G[3*N];
vector < long long > v;

void Upd(long long x) {
	while (x<=N) {
		G[x]++;
		x+=(x & -x);
	}
}

long long Get(long long x) {
	long long res=0;
	while (x>0) {
		res+=G[x];
		x-=(x & -x);
	}
	return res;
}

bool check(long long x) {
	long long b[N+5];
	vector < long long > s;
	for (int i=0; i<=N; i++) G[i]=0,b[i]=0;
	
	for (int i=1; i<=n; i++) {
		if (x<=a[i]) b[i]=1;
				else b[i]=-1;
		b[i]+=b[i-1];
		s.push_back(b[i]);
	}

	sort(s.begin(),s.end());
	
	map < int , int > F;
	
	long long tot=0;

	for (int i=0; i<s.size(); i++) 
		if (!F[s[i]]) F[s[i]]=++tot;
	
	long long res=0;
	
	for (int i=1; i<=n; i++) {
		if (b[i]>=0) res++; 
		res+=Get(F[b[i]]);
		Upd(F[b[i]]);
	}

	if (((1LL*n*(n+1))/2+1)/2<=res) return 1;
	return 0;
}

main () {
	ios::sync_with_stdio(false);
	cin>>n;
	
	for (int i=1; i<=n; i++) {
		cin>>a[i];
		v.push_back(a[i]);
	}
	
	sort(v.begin(),v.end());
	
	long long l=0,r=v.size()-1,mid;
	
	while (l<=r) {
		mid=(l+r)/2;
		if (check(v[mid])) { ANS=mid; l=mid+1; }
							  else r=mid-1;
	}
	
	cout<<v[ANS]<<endl;
}