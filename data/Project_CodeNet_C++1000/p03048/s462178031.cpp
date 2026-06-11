#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
const int inf = 1e9;
const ll INF = 1e18;
const double pi = 3.14159265358979323846;
#define rep(i,n) for(int i=0;i<n;i++)

int main(){
	int n,r,g,b;cin>>r>>g>>b>>n;
	int cnt=0;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			int m=n;
			m-=(i*r+j*g);
			if(m<0) break;
			if(m%b==0&&m/b>=0) {
				cnt++;
				//cout<<i<<" "<<j<<" "<<m/b<<"\n";
			}
		}
	}
	cout<<cnt<<"\n";
}