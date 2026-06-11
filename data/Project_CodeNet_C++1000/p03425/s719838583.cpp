#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using ll = long long;
const int INF = 2147483647;

int main(){
	int n;
	cin >> n;
	ll m=0,a=0,r=0,c=0,h=0;
	ll D[5];
	int P[10] = {0,0,0,0,0,0,1,1,1,2};
	int Q[10] = {1,1,1,2,2,3,2,2,3,3};
	int R[10] = {2,3,4,3,4,4,3,4,4,4};
	for(int i=0;i<n;i++){
		string s;
		cin >> s;
		if(s[0]=='M') m++;
		if(s[0]=='A') a++;
		if(s[0]=='R') r++;
		if(s[0]=='C') c++;
		if(s[0]=='H') h++;
	}
	D[0]=m, D[1]=a,D[2]=r, D[3]=c, D[4]=h;
	ll res =0;
	for(ll d=0;d<10;d++)
		res+=D[P[d]]*D[Q[d]]*D[R[d]];
	cout << res << endl;
	return 0;
}
