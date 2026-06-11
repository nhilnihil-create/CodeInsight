#include <bits/stdc++.h>
using namespace std;
struct edge {
    int to;     // 辺の行き先
    int weight; // 辺の重み
    edge(int t, int w) : to(t), weight(w) { }
};
using Graph = vector<vector<int>>;
using dou =long double;
string yes="yes";
string Yes="Yes";
string YES="YES";
string no="no";
string No="No";
string NO="NO";

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
#define rep(i, n)         for(int i = 0; i < (int)(n); i++)
#define brep(n)           for(int bit=0;bit<(1<<n);bit++)
#define erep(i,container) for (auto i : container)
#define irep(i, n)        for(int i = n-1; i >= (int)0; i--)
#define rrep(i,m,n) for(ll i = m; i < (ll)(n); i++)
#define reprep(i,j,h,w) rep(i,h)rep(j,w)
#define all(x) (x).begin(),(x).end()
#define VEC(type,name,n) std::vector<type> name(n);rep(i,n)std::cin >> name[i];
#define pb push_back
#define pf push_front
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define itn int
#define mp make_pair
#define sum(a) accumulate(all(a),0ll)
#define keta fixed<<setprecision
#define vvector(name,typ,m,n,a)vector<vector<typ> > name(m,vector<typ> (n,a))
#define vvvector(name,t,l,m,n,a) vector<vector<vector<t> > > name(l, vector<vector<t> >(m, vector<t>(n,a)));
#define vvvvector(name,t,k,l,m,n,a) vector<vector<vector<vector<t> > > > name(k,vector<vector<vector<t> > >(l, vector<vector<t> >(m, vector<t>(n,a)) ));
#define case std::cout << "Case #" <<qqq+1<<": "
#define res resize
#define as assign
#define ffor for(;;)
#define ppri(a,b) std::cout << a<<" "<<b << std::endl
#define pppri(a,b,c) std::cout << a<<" "<<b <<" "<< c<<std::endl
#define aall(x,n) (x).begin(),(x).begin()+(n)
 
typedef long long ll;
typedef pair<int,int> P;
//typedef long long T;
const int INF = 2000000000;
const ll INF64 = 922337203685477580ll;
const ll MOD = 1000000007ll;
long ggd(long a, long b) {//最小公倍数，最大公約数
	if(a<b)swap(a,b);
	if (b == 0) {
		return a;			
	}
	return ggd(b, a % b);
}
long lcm(long number1,long number2){
	return number1/ggd(number1,number2)*number2;	
}


int main(){
    int n,m;
    std::cin >> n>>m;
    string s,t;
    std::cin >> s>>t;
    ll g=ggd(n,m),l=lcm(n,m);
    ll a=n/g,b=m/g;
    //bool b=1;
    string ss,tt;
    rep(i,n){
        if(i%a==0)ss.pb(s[i]);
    }
    rep(i,m){
        if(i%b==0)tt.pb(t[i]);
    }
    if(ss==tt)std::cout << l << std::endl;
    else std::cout << -1 << std::endl;
    
    
}


