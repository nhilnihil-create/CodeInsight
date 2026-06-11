#include <bits/stdc++.h>
using namespace std;

typedef long long lint;
typedef pair<int, int> pii;

const int INF = 2e9;
const int MOD = 1e9+7;
const int MAX = 1e5+10;
const lint LNF = 2e18;

int n, A[MAX], S[MAX];
int T[2*MAX];
void clear(){ for(int i=0; i<=2*n+1; i++) T[i] = 0; }
void upt(int p){
	p += n+1;
	for(; p<=2*n+1; p+=p&(-p)) T[p]++;
}
int get(int p){
	int r = 0; p += n+1;
	for(; p>0; p-=p&(-p)) r+=T[p];
	return r;
}

bool check(int x){
	for(int i=1; i<=n; i++) S[i] = S[i-1] + (A[i]<x ? -1 : 1);
	clear();
	lint cnt = 0;
	for(int i=1; i<=n; i++){
		upt(S[i-1]);
		cnt += get(S[i]);
	}
	return 1LL*n*(n+1)/2 <= cnt*2;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);

	cin>>n;
	for(int i=1; i<=n; i++) cin>>A[i];

	int s = 0, e = 1e9;
	while(s<e){
		int m = (s+e+1)/2;
		if(check(m)) s = m;
		else e = m-1;
	}
	cout<<s<<'\n';

	return 0;
}
