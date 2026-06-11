#include<bits/stdc++.h>
#define fr(i,n) for(int i=0;i<(n);++i)
#define foor(i,a,b) for(int i=(a);i<=(b);++i)
#define rf(i,n) for(int i=(n);i--;)
#define roof(i,b,a) for(int i=(b);i>=(a);--i)
#define all(x) x.begin(),x.end()
#define Sort(x) sort(all(x))
#define Reverse(x) reverse(all(x))
#define PQ priority_queue
#define print(x) cout<<(x)<<endl
using namespace std;            typedef vector<int>  vi;
typedef long long ll;           typedef vector< ll>  vl;
typedef unsigned long long ull; typedef vector<ull>  vu;
typedef double dbl;             typedef vector<dbl>  vd;
typedef pair<int,int>pii;       typedef vector<pii>vpii; typedef map<int,int>mii;
typedef pair< ll, ll>pll;       typedef vector<pll>vpll; typedef map< ll, ll>mll;
typedef pair<dbl,dbl>pdd;       typedef vector<pdd>vpdd; typedef map<dbl,dbl>mdd;
typedef pair< ll,int>pli;       typedef vector<pli>vpli; typedef map< ll,int>mli;
typedef pair<dbl,int>pdi;       typedef vector<pdi>vpdi; typedef map<dbl,int>mdi;
template<typename T>vector<T>&operator<<(vector<T>&v,const T t){v.push_back(t);return v;}
template<typename T>multiset<T>&operator<<(multiset<T>&m,const T t){m.insert(t);return m;}
template<typename T>set<T>&operator<<(set<T>&s,const T t){s.insert(t);return s;}
template<typename T,typename U>PQ<T,vector<T>,U>&operator<<(PQ<T,vector<T>,U>&q,const T t){q.push(t);return q;}
template<typename T,typename U>istream&operator>>(istream&s,pair<T,U>&p){return s>>p.first>>p.second;}
template<typename T>istream&operator>>(istream&s,vector<T>&v){fr(i,v.size()){s>>v[i];}return s;}
template<typename T,typename U>ostream&operator<<(ostream&s,const pair<T,U>p){return s<<p.first<<" "<<p.second;}
template<typename T>ostream&operator<<(ostream&s,const vector<T>v){for(auto a:v){s<<a<<endl;}return s;}
const int MD=1e9+7;
vpli dijkstra(const int N,const vpli E[],const int s,const ll inf){vpli d;fr(i,N)d<<pli{inf,i};d[s].first=0;PQ<pli,vpli,greater<pli>>pq;pq<<(d[s]=pli{0,s});while(pq.size()){pli a=pq.top();pq.pop();int v=a.second;if(d[v].first>=a.first){for(pli e:E[v]){if(d[v].first+e.first<d[e.second].first){d[e.second]=pli{d[v].first+e.first,v};pq<<pli{d[v].first+e.first,e.second};}}}}return d;}
ll gcd(const ll a,const ll b){return a?gcd(b%a,a):b;}
ll pow(const ll a,const ll n,const int m){ll t;return n?(n&1?a>=0?a%m:~-m+~a%m:1)*(t=pow(a,n>>1,m),t*t%m)%m:1;}
ll C2(const int n){return(ll)n*~-n/2;}
 
main(){cin.tie(0);ios::sync_with_stdio(false);
	using P=pair<ll,double>;
	set<P>s;
	ll k=0,p=1;
	for(ll j=0;j<=15;++j){
		for(ll i=1;i<=1000;++i){
			ll t=i*p+k;
			ll a=0;
			for(ll u=t;u;u/=10){
				a+=u%10;
			}
			s<<P{t,(double)t/a};
		}
		k=k*10+9;
		p*=10;
	}
	vector<P>v;
	for(P a:s){
		v<<a;
	}
	Reverse(v);
	vl z;
	double m=1e18;
	for(P a:v){
		if(a.second<=m){
			z<<a.first;
			m=a.second;
		}
	}
	Reverse(z);
	int K;
	cin>>K;
	fr(i,K){
		print(z[i]);
	}
}
