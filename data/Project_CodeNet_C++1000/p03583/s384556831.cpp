#include <bits/stdc++.h>
using ll = long long;
using namespace std;
#define rep(i,n) for(int i=0, i##_len=(int)(n); i<i##_len; i++)
#define reps(i,n) for(int i=1 , i##_len=(int)(n);i<=i##_len;i++)
#define rrep(i,n) for(int i=((int)(n)-1);i>=0;i--)
#define rreps(i,n) for(int i=((int)(n));i>0;i--)
#define repi(i,x) for(auto i=(x).begin(),i##_fin=(x).end();i!=i##_fin;i++)
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define solve(a) ((a)?"Yes":"No")
typedef vector<int> Vi;
typedef vector<Vi> VVi;
typedef pair<int , int> Pi;
typedef vector<Pi> VPi;
typedef vector<long long> V;
typedef vector<V> VV;
typedef pair<long long , long long> P;
typedef vector<P> VP;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1;} return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1;} return 0;}
const long long INFLL = 1LL<<60;
const int INF = 1<<30;
const double PI=acos(-1);
int main(){
	ll N;
	cin >>N;
	ll w;
	ll mother;
	for(ll h=max(1LL,N/4LL);;h++){
		if(4LL*h==N){continue;}
		for(ll n=max((N*h)/(4LL*h-N),1LL);n<=3500LL;n++){
			/* 4/N = 1/h +1/n+ 1/w
				4hnw=Nnw+Nhw+Nhn
				4hnw-Nnw-Nhw=Nhn
				w(4hn-Nn-Nh)=Nhn
				4hn-Nn>Nh
				n(4h-N)>Nh
				n>(Nh/(4h-N))
				4h-N>0
				h>N/4
			*/
			clog << h << " " << n << " --  " << mother << endl;
			mother=4 * h * n - N *(n+h);
			if(mother <=0){//4*h*n < Nn+Nh-> 4hn-Nn<Nh
			// n(4h-N)<Nh ==> n<Nh/(4h-N)

			/*
				4h-N >0
				4h>N
				h>N/4
			*/
				continue;
			}
		//	clog << (4*h*n - N*n - N*h)<<endl;
			if ( (N * h * n) % mother == 0)
			{
				w = (N*h*n) / (mother);
				printf("%lld %lld %lld\n",h,n,w);
				return 0;
			}
			
		}
	}
	
}