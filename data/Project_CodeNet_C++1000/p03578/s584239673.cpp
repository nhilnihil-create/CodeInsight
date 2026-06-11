#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const int inf = 1e9;
const ll INF = 1e18;
const double pi = 3.14159265358979323846;
#define rep(i,n) for(ll i=0;i<n;i++)

int main(){
	int n;cin>>n;
	map<int,int> mpn;
	rep(i,n){
		int a;cin>>a;
		mpn[a]++;
	}
	int m;cin>>m;
	rep(i,m){
		int a;cin>>a;
		mpn[a]--;
		if(mpn[a]<0){
			cout<<"NO"<<"\n";
			return 0;
		}
	}
	cout<<"YES"<<"\n";
}