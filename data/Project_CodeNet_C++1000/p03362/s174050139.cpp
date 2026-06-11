#include <bits/stdc++.h>

#define rep2(x,fr,to) for(int (x)=(fr);(x)<(to);(x)++)
#define rep(x,to) for(int (x)=0;(x)<(to);(x)++)
#define repr(x,fr,to) for(int (x)=(fr);(x)>=(to);(x)--)
#define all(c) (c).begin(),(c).end()
#define sz(v) (int)(v).size()

using namespace std;
typedef long long ll; typedef vector<int> VI; typedef pair<int,int> pii;
const int MD = (int)1e9 + 7; typedef vector<ll> VL;
void dbg(){ cerr << "\n"; }  template <class T, class ...T2> void dbg(const T& fst, const T2&...rst){ cerr << fst << ": "; dbg(rst...); }
template <class T, class T2> void amax(T& a,T2 b){ if(a < b) a = b;}

vector<bool> prime(60000);
VI pr;
void eratos ( int n){
	prime[2] = true; prime[0] = prime[1] = false;
	for(int i = 3; i <= n; i += 2) prime[i] = true, prime[i+1] = false;
	int limit = (int)sqrt((double)n) + 1;
	for(int i = 3; i <= limit; i += 2){
		if(!prime[i]) continue;
		for(int j = i * i, k = i * 2; j <= n; j += k) prime[j] = false;
	}
	rep(i, n+1) if(prime[i]) pr.push_back(i);
}

int main()
{
	cin.tie(0); ios_base::sync_with_stdio(false);
	int n;
	cin >>n;
	eratos(55555);
	int ct = 1;
	for(auto x: pr) if(x%5==1){
		cout <<x <<" ";
		if(ct++ >=n) break;
	}
	cout <<"\n";
	return 0;
}
