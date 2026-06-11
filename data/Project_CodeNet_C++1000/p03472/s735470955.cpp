#include<bits/stdc++.h>
using namespace std;

int main() {
	int N,H; cin>>N>>H;
	vector<int> a(N), b(N);
	for(int i=0; i<N; i++)
		cin>>a[i]>>b[i];
	sort(a.rbegin(),a.rend());
	sort(b.rbegin(),b.rend());
	int mx=a[0], ret=0;
	for(int i=0; i<N; i++) 
		if(b[i]>mx&&H>0) H-=b[i], ret++;
	if(H>0) ret+=(H+mx-1)/mx;
	cout<<ret<<"\n";
	return 0;
}