#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
#define ALL(v)   (v).begin(),(v).end()
#define debug(x) cerr<<#x<<": "<<(x)<<endl
#define INF      (int)1e9
#define EPS      (double)1e-9
#define MOD      ((int)1e9+7)
using namespace std;
typedef long long     llong;
typedef vector<int>   vi;
typedef vector<vi >   vvi;
typedef vector<vvi >  vvvi;
typedef pair<int,int> pii;
template<class Type> void line(const Type &a){int cnt=0;for(const auto &elem:a){if(cnt++)cerr<<' ';cerr<<elem;}cerr<<endl;}

int main(){
	int n;
	cin>>n;
	
	vi a(n);
	REP(i,n){
		cin>>a[i];
		a[i]-=i+1;
	}
	sort(ALL(a));
	//line(a);
	
	int b=a[n/2];
	//debug(b);
	llong ans=0;
	REP(i,n) ans+=abs((llong)a[i]-b);
	
	cout<<ans<<endl;
}