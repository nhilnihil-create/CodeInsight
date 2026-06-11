#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
typedef pair<ll,ll> pll;
void read(int& x){ scanf("%d",&x); }
void read(ll& x){ scanf("%lld",&x); }
template<typename T,typename... Args>
void read(T& a,Args&... b){ read(a); read(b...); }
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define eb emplace_back
#define x first
#define y second

char s[8010];
int x, y;
int n;

vector<int> key[2];

bool make(int x, int k){
	auto& v = key[k];
	bitset<16001> bs; bs[8000] = 1;
	for(int t:v){
		bs = (bs << t) | (bs >> t);
	}
	return x<=n && bs[8000+x];
}

int main()
{
	scanf("%s", s+1);
	read(x, y);
	n = strlen(s+1);
	int sp = n+1;
	for(int i=1; i<=n; ++i){
		if(s[i] != 'F'){
			sp = i;
			break;
		}
		--x;
	}
	int pos = 0;
	for(int i=sp; i<=n; ++i){
		if(s[i] == 'T') pos ^= 1, key[pos].pb(0);
		else ++key[pos].back();
	}
	if(make(abs(x), 0) && make(abs(y), 1)){
		puts("Yes");
	} else {
		puts("No");
	}
	return 0;
}
