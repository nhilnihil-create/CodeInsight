#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n,a,b,cnt=1,ans=0;
	cin>>n;
	cin>>a;
	for(int i=0;i<n-1;i++){
		cin>>b;
		if(b==a){
			cnt++;
		}else{
			ans+=cnt/2;
			cnt=1;
		}
		a=b;
	}
	ans+=cnt/2;
	cout<<ans<<endl;
	return 0;
}
