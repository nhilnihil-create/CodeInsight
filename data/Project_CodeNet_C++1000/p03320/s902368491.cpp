#include <bits/stdc++.h> 

using namespace std;

#define fcout(d) cout << fixed << setprecision(d)
#define rep(i,n) for(int (i)=0; (i)<n; ++(i))
#define rep1(i,n) for(int (i)=1; (i)<=n; ++(i))
#define repU(i,bottom,ceiling) for(int (i) = (bottom); (i) <= (ceiling); ++(i))
#define repD(i,ceiling,bottom) for(int (i) = (ceiling); (i) >= (bottom); --(i))
#define pub push_back
#define pob pop_back
#define prf printf
#define scf scanf
#define mkp make_pair
#define fir first
#define sec second
#define clr(a) memset((a),0,sizeof(a))

typedef long long ll;
typedef double db;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<double> vdb;
typedef vector<vector<double>> vvdb;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;
typedef vector<pair<int,int>> vpii;
typedef pair<int,int> pii;

const vector<pair<int,int>> DIR = { {1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,1},{-1,-1},{1,-1} };
const int INF = (int)2e9 + 1e8;
const int MOD = (int)1e9 + 7;

template<typename T,typename U>                                                   
inline pair<T,U> operator+(const pair<T,U> & l,const pair<T,U> & r) {   
    return {l.fir+r.fir,l.sec+r.sec};                                    
} 

template<typename T,typename U> 
inline pair<T,U> operator-(const pair<T,U> & l,const pair<T,U> & r) {   
    return {l.fir-r.fir,l.sec-r.sec};                                    
} 

template<typename T,typename U>                                                   
inline pair<T,U> operator*(const pair<T,U> & l,const pair<T,U> & r) {   
    return {l.fir*r.fir,l.sec*r.sec};                                    
}

template<typename T> inline T gcd(T a,T b){ if(a % b){ return gcd(b,a % b); }else{ return b; } }

template<typename T> inline T lcm(T a,T b){ return a / gcd(a,b) * b; }

inline int Pow(const long long n,long long m,const int mod = MOD){
	long long res = 1,pow = n;
	while(m) {
		if(m & 1) res = (res * pow) % mod;
		pow = (pow * pow) % mod;
		m >>= 1;
	}
	return res;
}

inline vector<int> Frac(const int range,const int mod = MOD){
	vector<int> frac;
	frac.push_back(1);
	for(int i = 1; i <= range; ++i) frac.push_back((long long)frac.back() * i % mod);
	return frac;
}

inline int Comb(const int n,const int m,const int mod = MOD){
	if(n < m || m < 0) return 0;
	vector<int> frac(Frac(n,mod));
	long long rev = Pow((long long)frac[m] * frac[n-m] % mod,mod-2,mod);
	return rev * frac[n] % mod;
}

template<typename T> inline bool v_find(const vector<T> v,const T obj){
	auto itr = find(v.begin(), v.end(), obj);
	size_t index = distance(v.begin(),itr);
	if (index != v.size()) { return true; }
	return false; 
}

template<typename T> inline bool v_erase(vector<T> &v,const T obj){
	auto itr = find(v.begin(), v.end(), obj);
	size_t index = distance(v.begin(),itr);
	if (index != v.size()) {
		v.erase(itr);
		return true;
	}
	return false;	
}

template<class T,class U> inline auto LB(const T v,const U in){ return lower_bound(v.begin(),v.end(),in); }

template<class T,class U> inline auto UB(const T v,const U in){ return upper_bound(v.begin(),v.end(),in); }

ll K;

db cal(ll x){
	ll s=0,m=x;
	while(m){
		s+=m%10;
		m/=10;
	}
	return (db)x/s;
}

inline void solve(){
	ll n=1;
	rep(j,K){
		db res=1e15+1;
		ll s;
		rep(i,16){
			ll x=(n/(ll)pow(10,i)+1)*(ll)pow(10,i)-1;
			db t=cal(x);
			if(t<res){
				res=t;
				s=x;
			}
		}
		cout<<s<<endl;
		n=s+1;
	}
	return;
}

inline void input(){
	cin>>K;
	return;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	input();
	solve();
	return 0;
}



