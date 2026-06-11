#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
 
int main() {
  long long N,ans;
	ans=0;
	cin>>N;
	vector<long long> a(N);
	rep(i,N)cin>>a[i];
	sort(a.rbegin(),a.rend());
	for(long long i=0;i<N;i++){
		if(i%2==0)ans+=a[i];
		else ans-=a[i];
	}
	cout<<ans<<endl;
}