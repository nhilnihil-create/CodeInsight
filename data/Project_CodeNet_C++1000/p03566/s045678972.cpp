#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
#define a first
#define b second
#define sz(x) (ll)((x).size())
#define pb push_back
#define mp make_pair 
#define bg begin()
#define ed end()
#define all(x) (x).bg,(x).ed
#define rep(i,n) for(ll i=0;i<(n);i++)
#define rep1(i,n) for(ll i=1;i<=(n);i++)
#define FOR(i,a,b) for(ll i=(a);i<(b);i++)
const double INF=1000000000000000.0;

template<class T> inline bool chmin(T& a, T b){if(a>b){a=b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b){if(a<b){a=b;return true;}return false;}

int main(){
	//input
	ll N; cin>>N;
	vector<ll> t(N);
	rep(i,N) cin>>t[i];
	vector<ll> v(N);
	rep(i,N) cin>>v[i];

	vector<P> A(N+1);
	A[0]=P(0,0);
	ll tmpt=0;
	rep(i,N){
		tmpt+=t[i];
		A[i+1]=P(tmpt,v[i]);
	}
	vector<pair<ll,P>> B(N+1);
	rep(i,N){
		if(A[i+1].b>A[i].b) B[i]=mp(A[i].a,P(1ll,A[i].b-A[i].a));
		else B[i]=mp(A[i].a,P(-1ll,A[i].a+A[i+1].b));
	}
	B[N]=mp(A[N].a,P(-1ll,A[N].a));

	/*
	rep(i,N+1){
		printf("A[%lld].a=%lld A[%lld].b=%lld\n",i,A[i].a,i,A[i].b);
	}
	cout<<endl;
	rep(i,N+1){
		printf("B[%lld].a=%lld B[%lld].b.a=%lld B[%lld].b.b=%lld\n",i,B[i].a,i,B[i].b.a,i,B[i].b.b);
	}
	*/

	double tmp,ans=0;

	for(double i=0.0;i<=(double)tmpt;i+=0.5){
		double maxV=INF;
		rep(j,N+1){ //B(条件)をすべて見る
			if(B[j].b.a==1){
				if(i>=B[j].a){ //B[j]の条件適用
					chmin(maxV,i*B[j].b.a+B[j].b.b);
				}
			}
			else{
				if(i<=B[j].a){
					chmin(maxV,i*B[j].b.a+B[j].b.b);
				}
			}
		}

		ll sub=0;
		while(sub<=N){
			if((double)A[sub].a>=i) break;
			sub++;
		}
		chmin(maxV,(double)A[sub].b);

		//cout<<i<<":"<<sub<<endl;
		//printf("i:%.1f maxV:%.12f\n",i,maxV);

		if(i==0) tmp=maxV;
		else{
			ans+=(maxV+tmp)*0.25;
			tmp=maxV;
		}
	}

	printf("%.10f",ans);
}