#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<math.h>
using namespace std;
typedef long long ll;
typedef vector<int> VI;
#define REP(i,n) for(int i=0;i<n;i++)
#define eREP(i,n) for(int i=0;i<=n;i++)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define eFOR(i,a,b) for(int i=(a);i<=(b);++i)
#define SORT(c) sort((c).begin(),(c).end())
#define rSORT(c) sort((c).rbegin(),(c).rend())
#define LB(x,a) lower_bound((x).begin(),(x).end(),(a))
#define UB(x,a) upper_bound((x).begin(),(x).end(),(a))
#define INF 1000000000
#define LLINF 9223372036854775807
#define mod 1000000007
//vector<vector<int> > dp;
//vector<vector<vector<int> > > vvvi;
//dp=vector<vector<int> >(N, vector<int>(M,0));
//vector<pair<int,int> > v;
//v.push_back(make_pair(x,y));

int main(){
cin.tie(0);
ios::sync_with_stdio(false);

	ll n,p;
	cin>>n>>p;
	ll ans=1;
	if(n==1){
		cout<<p<<endl;
		return 0;
	}
	ll i=2;
	
	while(p>1){
		ll cnt=0;
		while(p%i==0){
			p/=i;
			cnt++;
			if(cnt>=n){
				ans*=i;
				cnt=0;
			}
		}
		i++;
		if(i>sqrt(p)){
			break;
		}
	}
	cout<<ans<<endl;
	return 0;
}















