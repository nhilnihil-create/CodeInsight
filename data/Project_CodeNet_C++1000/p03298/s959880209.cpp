#include<bits/stdc++.h>

#define SORT(v) sort(v.begin(),v.end())
#define si(n) scanf("%d",&n)
#define sii(n,m) scanf("%d %d",&n,&m)
#define sl(n) scanf("%lld",&n)
#define sll(n,m) scanf("%lld %lld",&n,&m)
#define ss(cad) scanf("%s",cad)
#define PB push_back
#define fst first
#define scn second
#define DBG(x) cerr << #x << " = " << (x) << endl; 
#define M 1000000007
#define N_MAX 100010

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ll> vl;
typedef pair<int,int> pi;
typedef vector<pi> vp;

char cad[100];

int main(){
	int n;
	si(n);
	ss(cad);
	vector<pi> vec1(1<<n), vec2(1<<n);
	map<string, int> mapa;
	int pos = 0;
	for(int mask = 0; mask < (1<<n); mask++){
		string a, b;
		for(int i = n-1; i >= 0; i--){
			if((mask&(1<<i)) == 0)
				a.push_back(cad[n-1-i]);
			else
				b.push_back(cad[n-1-i]);
		}
		reverse(b.begin(), b.end());
		if(mapa.count(a) == 0)
			mapa[a] = pos++;
		if(mapa.count(b) == 0)
			mapa[b] = pos++;
		vec1[mask] = {mapa[a], mapa[b]};
	}

	for(int mask = 0; mask < (1<<n); mask++){
		string a, b;
		for(int i = n-1; i >= 0; i--){
			if((mask&(1<<i)) == 0)
				a.push_back(cad[n+n-1-i]);
			else
				b.push_back(cad[n+n-1-i]);
		}
		reverse(b.begin(), b.end());
		if(mapa.count(a) == 0)
			mapa[a] = pos++;
		if(mapa.count(b) == 0)
			mapa[b] = pos++;
		vec2[mask] = {mapa[b], mapa[a]};
	}
	sort(vec1.begin(), vec1.end());
	sort(vec2.begin(), vec2.end());
	ll ans = 0;
	for(int i = 0; i < vec1.size(); i++){
		int cnt = upper_bound(vec2.begin(), vec2.end(), vec1[i]) - lower_bound(vec2.begin(), vec2.end(), vec1[i]);
		ans += cnt;
	}
	printf("%lld\n", ans);	
	return 0;
}
