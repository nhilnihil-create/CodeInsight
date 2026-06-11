#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define fi first
#define se seconde
#define pb push_back()
#define SZ(x) ((int)(x).size())
typedef long long ll;
typedef pair<int,int> pii;
typedef double db;
ll k,n,ans;
int main(){
	cin>>n>>k;
	if(!k){
		cout<<n*n<<endl;
		return 0;
	}
	rep(i,k+1,n){
		ans+=(n/(ll)i*((ll)i-k));
		if(n%i){
			ans+=max(0ll,n%i-k+1);
		}
	}
	cout<<ans<<endl;
	return 0;
}