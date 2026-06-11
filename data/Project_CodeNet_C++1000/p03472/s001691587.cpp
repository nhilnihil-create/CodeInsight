#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define FOR(i,a,b) for(int i=(a); i<=(b); i++)
#define rep(i,n) for(int i = 0; i < (n); i++)
#define loop(k) rep(author_is_masa,k)
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

signed main(){
	int n,h;
	cin>>n>>h;
	vi a(n),b(n);
	rep(i,n)cin>>a[i]>>b[i];

	int maxa=0;
	rep(i,n)chmax(maxa,a[i]);
	int sum=0;
	int cnt=0;
	sort(all(b));
	rep(i,n)if(maxa<b[n-i-1]){
		sum+=b[n-1-i];
		cnt++;
		if(sum>=h){
			cout<<cnt<<endl;
			return 0;
		}
	}
	// cout<<"sum="<<sum<<endl;
	h-=sum;
	cout<<cnt+(h+maxa-1)/maxa<<endl;

	return 0;
}

