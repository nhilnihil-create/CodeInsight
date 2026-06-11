#include<bits/stdc++.h>
using namespace std; 
typedef long long ll;
typedef long double ld;
#define fi first
#define se second
const ll mod = 1e9+7;
const int N = 1e5+205;
ll inp[N][3];
void solve(){
	int n; 
	cin>>n; 
	for(int i=1;i<n;i++){
		for(int j=0;j<3;j++)cin>>inp[i][j];
	}
	for(int i=1;i<=n;i++){
		ll cur = 0;
		for(int j=i;j<n;j++){
			if(cur<inp[j][1]){
				cur = inp[j][1];
			}
			else if(cur%inp[j][2]!=0){
				cur+=inp[j][2]-cur%inp[j][2];
			}
			cur+=inp[j][0];
		}
		cout<<cur<<endl;
	}
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t=1; 
//	cin>>t; 
	while(t--){
		solve();
	}
	return 0;
}
