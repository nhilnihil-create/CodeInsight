#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const int inf = 1e9;
const ll INF = 1e18;
const double pi = 3.14159265358979323846;
#define rep(i,n) for(ll i=0;i<n;i++)

int main(){
	ll k,a,b;cin>>k>>a>>b;
	ll v=1,y=0;

	while(k){
		if(v>=a){
			if(b-a>2&&k>=2){
				v+=b-a;
				k-=2;
			}

			else{
				v++;
				k--;
			}
		}
		else {
			v++;
			k--;
		}
	}

	cout<<v<<endl;
}