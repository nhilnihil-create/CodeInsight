#include<bits/stdc++.h>
using namespace std;
#define fr(i,n) for(int i=0;i<(n);++i)
#define foor(i,a,b) for(int i=(a);i<=(b);++i)
#define rf(i,n) for(int i=(n);i--;)
#define roof(i,b,a) for(int i=(b);i>=(a);--i)
#define all(x) x.begin(),x.end()
#define Sort(x) sort(all(x))
#define PQ priority_queue
#define print(x) cout<<(x)<<"\n"
typedef long long ll;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
typedef pair<ll,int>pli;
typedef vector<int>vi;
typedef vector<ll>vl;
typedef vector<pii>vpii;
typedef vector<pll>vpll;
typedef vector<pli>vpli;
typedef map<int,int>mii;
typedef map<ll,ll>mll;
template<typename T>vector<T>&operator<<(vector<T>&v,const T t){v.push_back(t);return v;}
template<typename T>multiset<T>&operator<<(multiset<T>&m,const T t){m.insert(t);return m;}
template<typename T>set<T>&operator<<(set<T>&s,const T t){s.insert(t);return s;}
template<typename T,typename U>PQ<T,vector<T>,U>&operator<<(PQ<T,vector<T>,U>&q,const T t){q.push(t);return q;}
template<typename T,typename U>istream&operator>>(istream&s,pair<T,U>&p){return s>>p.first>>p.second;}
template<typename T>istream&operator>>(istream&s,vector<T>&v){fr(i,v.size()){s>>v[i];}return s;}
template<typename T,typename U>ostream&operator<<(ostream&s,const pair<T,U>p){return s<<p.first<<" "<<p.second;}
template<typename T>ostream&operator<<(ostream&s,const vector<T>v){for(auto a:v){s<<a<<endl;}return s;}
vpli dijkstra(const int N,const vpli E[],const int s,const ll inf){vpli d;fr(i,N)d<<pli{inf,i};d[s].first=0;PQ<pli,vpli,greater<pli>>pq;pq<<(d[s]=pli{0,s});while(pq.size()){pli a=pq.top();pq.pop();int v=a.second;if(d[v].first>=a.first){for(pli e:E[v]){if(d[v].first+e.first<d[e.second].first){d[e.second]=pli{d[v].first+e.first,v};pq<<pli{d[v].first+e.first,e.second};}}}}return d;}
ll gcd(ll a,ll b){return a?gcd(b%a,a):b;}

main(){cin.tie(0);ios::sync_with_stdio(false);
	int N;
	cin>>N;
	vi a(N),b(N);
	cin>>a>>b;
	int z=0;
	rf(k,29){
		for(int&_:a)_&=(1<<k+1)-1;
		for(int&_:b)_&=(1<<k+1)-1;
		Sort(b);
		ll x=0;
		for(int&_:a){
			x+=lower_bound(all(b),(2<<k)-_)-lower_bound(all(b),(1<<k)-_);
			x+=b.end()-lower_bound(all(b),(3<<k)-_);
		}
		z|=(x&1)<<k;
	}
	print(z);
}
