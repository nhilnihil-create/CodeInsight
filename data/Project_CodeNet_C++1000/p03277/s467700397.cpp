#include <bits/stdc++.h>

using namespace std;

#ifdef DEBUG_MODE
	#define DBG(n) n;
#else
	#define DBG(n) ;
#endif
#define REP(i,n) for(ll (i) = (0);(i) < (n);++i)
#define PB push_back
#define MP make_pair
#define FI first
#define SE second
#define SHOW1d(v,n) {for(int W = 0;W < (n);W++)cerr << v[W] << ' ';cerr << endl << endl;}
#define SHOW2d(v,i,j) {for(int aaa = 0;aaa < i;aaa++){for(int bbb = 0;bbb < j;bbb++)cerr << v[aaa][bbb] << ' ';cerr << endl;}cerr << endl;}
#define ALL(v) v.begin(),v.end()
#define Decimal fixed<<setprecision(20)
#define INF 1000000000
#define LLINF 1000000000000000000LL
#define MOD 1000000007

typedef long long ll;
typedef pair<ll,ll> P;

template<typename T>
class segtree{
	int nn;vector<T> dat;T ZERO;
public:
	segtree(int n_,T zero):ZERO(zero){
	  nn = 1;
	  while(nn < n_)nn*=2;
	  dat.resize(2*nn);
	  for(int i = 0;i < 2*nn;i++)dat[i] = ZERO;
	}
	void update(int k, int a){
	  k += nn - 1;dat[k] = a;
	  while(k > 0){
		k = (k-1)/2;
		dat[k] = function(dat[k*2+1],dat[k*2+2]);
	  }
	}
	
	T function(T a,T b){
		return a + b;
	}
	
	T get(int k){return dat[k+nn-1];}
	T que(int a,int b){
		T L = ZERO,R = ZERO;
		int A = a + nn - 1;
		int B = b + nn - 1;
		while(A < B){
			if((A & 1) == 0)L = function(L,dat[A++]);
            if((B & 1) == 0)R = function(R,dat[--B]);
            A = A >> 1;
            B = B >> 1;
		}
		return function(L,R);
	}
};

ll n;
ll v[111111];
ll now[111111];

bool check(ll mid){
	ll ret = 0;
	REP(i,n){
		if(v[i] >= mid)now[i] = 1;
		else now[i] = -1;
	}
	
	ll mi = 0;
	REP(i,n){
		now[i+1] += now[i];
		mi = min(mi,now[i]);
	}

	REP(i,n)now[i] -= mi;
	
	segtree<ll> sg(n+2,0);
	sg.update(-mi,1);
	
	REP(i,n){
		ret += sg.que(0,now[i]+1);
		sg.update(now[i],sg.get(now[i])+1);
	}

	return ret >= n * n / 4;
}

int main(){
	
	cin >> n;
	REP(i,n)cin >> v[i];
	
	ll tb = LLINF;
	ll ub = -LLINF;
	
	if(n == 1){
		cout << v[0] << endl;
		return 0;
	}
	
	while(abs(tb-ub) > 1){
		ll mid = (tb + ub) / 2;
		if(check(mid))ub = mid;
		else tb = mid;
		DBG(cout << mid << endl;)
	}
	
	cout << ub << endl;
	
	return 0;
}
