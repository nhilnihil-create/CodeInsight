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
	int b[n];
	rep(i,n) {
		cin>>b[i];
		if(b[i]>i+1){
			//cout<<i<<"\n";
			cout<<-1<<"\n";
			return 0;
		}
	}

	int c[n]={};
	rep(i,n){
		int d=(i+1)-b[i];
		if(c[n-1-d]==0) c[n-1-d]=b[i];//まだそこまで到達しなければそのまま入れる
		else{
			for(int j=0;j<n-1-d;j++){//到達してればずらす
				c[j]=c[j+1];
			}
			c[n-1-d]=b[i];
		}
	}
	rep(i,n) cout<<c[i]<<"\n";
}