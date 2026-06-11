#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin, (x).rend()
#define endl '\n'
#define first F
#define second S
typedef long long ll;

int pass(int m, int k){
	int cnt=0;
	while(m<k){
		m*=2;
		cnt++;
	}
	return cnt;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,k; cin>>n>>k;
	double ans=0;
	for(int i=1; i<=n; i++){
		int x = 1<<pass(i, k);
		double prob = 1.0/(x*1.0);
		ans+=((1.0/n*1.0)*prob);
	}
	cout<<fixed<<setprecision(12)<<ans<<endl;
	return 0;
}
