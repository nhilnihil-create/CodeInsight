#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define FOR(i,a,b) for(int i=(a); i<=(b); i++)
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define chmin(a,b) if((a)>(b)) (a)=(b);
#define chmax(a,b) if((a)<(b)) (a)=(b);
#define vi vector<int>
#define pii pair<int,int>
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define pb push_back
#define pf push_front
int gcd(int a,int b){/*a>=0,b>=0,￢(a=b=0)*/
  while(min(a,b)>0){if(a<b)swap(a,b);a%=b;}return max(a,b);
}
int dx[]={1,0,-1,0,1,-1,-1,1};
int dy[]={0,1,0,-1,1,1,-1,-1};
const int MOD = 1e9+7;
const long long INF = 1e18+10;

/*--------------------------------------------------------------------*/
int like[100100];
bool isprime(int n){
	if(n==1)return false;

	for(int i=2;i*i<=n;i++){
		if(n%i==0)return false;
	}
	return true;
}
signed main(){
	// vi like(100100,0);
	for(int i=1;i<=100000;i+=2){
		if(isprime(i)&&isprime((i+1)/2)) like[i]=1;
	}
	rep(i,100010){
		like[i+1]+=like[i];
	}
	
	int q;
	cin>>q;
	rep(i,q){
		int l,r;
		cin>>l>>r;
		cout<<like[r]-like[l-1]<<endl;
	}

	return 0;
}
