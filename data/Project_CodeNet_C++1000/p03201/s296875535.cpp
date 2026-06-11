#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<utility>
#include<map>
#include<set>
#include<queue>
#include<math.h>
using namespace std;
#define mod (1000000000+7)
#define N (10007)
#define INF 1e16
typedef long long ll;
typedef pair<int,int> P;

int main(void){
	ll n;
	cin>>n;
	vector<ll>a(n);
	map<ll,ll>cnt;
	for(ll i=0;i<n;i++){
		cin>>a[i];
		cnt[a[i]]++;
	}
	sort(a.begin(),a.end(),greater<ll>());
	ll ans=0;
	for(ll i=0;i<n;i++){
		if(cnt[a[i]]==0)continue;
		for(ll j=33;j>=1;j--){
			ll power=(ll)1<<j;
			if(power<=a[i])break;
			if(cnt[power-a[i]]>0){
				if(power==2*a[i]&&cnt[a[i]]==1)continue;
				ans++;
				cnt[a[i]]--;
				cnt[power-a[i]]--;
				break;
			}
		}
	}
	cout<<ans<<endl;
    return 0;
}