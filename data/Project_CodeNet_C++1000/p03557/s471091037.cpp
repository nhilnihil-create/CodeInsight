#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll high[100005];
ll mid[100005];
ll low[100005];
ll psum[100005];
ll ret = 0;
int main(){
	int n;
	cin>>n;
	for(int i=1; i<=n; i++) cin>>high[i];
	for(int i=1; i<=n; i++) cin>>mid[i];
	for(int i=1; i<=n; i++) cin>>low[i];
	sort(high+1,high+n+1);
	sort(mid+1,mid+n+1);
	sort(low+1,low+n+1);
	for(int i=1; i<=n; i++){
		psum[i] = (n+1)-(upper_bound(low+1,low+n+1,mid[i])-low);
	}
	for(int i=n-1; i>=1; i--){
		psum[i]+=psum[i+1];
	}
	for(int i=1; i<=n; i++){
		int index = upper_bound(mid+1,mid+n+1,high[i])-mid;
		ret+=psum[index];
	}
	cout<<ret;
}