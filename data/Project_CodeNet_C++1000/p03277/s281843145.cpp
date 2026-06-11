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
	int n;vector<T> dat;T ZERO;
public:
	segtree(int n_,T zero):ZERO(zero){
	  n = 1;
	  while(n < n_)n*=2;
	  dat.resize(2*n);
	  for(int i = 0;i < 2*n;i++)dat[i] = ZERO;
	}
	void update(int k, int a){
	  k += n - 1;dat[k] = a;
	  while(k > 0){
		k = (k-1)/2;
		dat[k] = function(dat[k*2+1],dat[k*2+2]);
	  }
	}
	
	T function(T a,T b){
		return a + b;
	}
	
	T get(int k){return dat[k+n-1];}
	T que(int a,int b){
		T L = ZERO,R = ZERO;
		int A = a + n - 1;
		int B = b + n - 1;
		while(A < B){
			if((A & 1) == 0)L = function(L,dat[A++]);
            if((B & 1) == 0)R = function(R,dat[--B]);
            A = A >> 1;
            B = B >> 1;
		}
		return function(L,R);
	}
};

bool check(ll mid,vector<ll> &v){
	ll ret = 0;
	vector<ll> now;
	REP(i,v.size()){
		if(v[i] >= mid)now.PB(1);
		else now.PB(-1);
	}
	
	DBG(SHOW1d(now,now.size()));
	
	ll mi = 0;
	REP(i,now.size()){
		if(i < now.size() - 1)now[i+1] += now[i];
		mi = min(mi,now[i]);
	}
	DBG(SHOW1d(now,now.size()));
	REP(i,now.size())now[i] -= mi;
	
	segtree<ll> sg(v.size()+2,0);
	sg.update(-mi,1);
	
	DBG(SHOW1d(now,now.size()));
	DBG(cout << "   ";REP(i,now.size())cout << sg.get(i) << ' ';cout << ret << endl;)
	REP(i,now.size()){
		ret += sg.que(0,now[i]+1);
		sg.update(now[i],sg.get(now[i])+1);
		DBG(cout << "   ";REP(i,now.size())cout << sg.get(i) << ' ';cout << ret << endl;)
	}
	
	DBG(cout << ret << ' ' << v.size() * (v.size()+1) / 4 << endl;)
	return ret >= v.size() * v.size() / 4;
}

int main(){
	
	int n;cin >> n;
	vector<ll> v(n);
	REP(i,n)cin >> v[i];
	
	ll tb = LLINF;
	ll ub = -LLINF;
	
	if(n == 1){
		cout << v[0] << endl;
		return 0;
	}
	
	while(abs(tb-ub) > 1){
		ll mid = (tb + ub) / 2;
		if(check(mid,v))ub = mid;
		else tb = mid;
		DBG(cout << mid << endl;)
	}
	
	cout << ub << endl;
	
	return 0;
}
