#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
void solve(){
	int n;
	cin>>n;
int ans = 0;
	for(int i=1;i*i<=n;i++){
		ans = i;
	}
	cout<<ans*ans<<endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cout<<fixed<<setprecision(12);
	int t=1;
//	cin>>t;
	while(t--)solve();
  return 0;
}
