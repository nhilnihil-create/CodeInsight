#include<bits/stdc++.h>
using namespace std;

const long long INF = 1000000000;

typedef long long ll;

#define writeln(n) cout<<n<<"\n"
#define rep(i,n) for(int i=0; i<(n); ++i)

typedef pair<int, int> P;
typedef pair<string, int> Psi;


ll d[6];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);


	ll n;cin>>n;

	ll mi =10000000000000000;

	rep(i,5){
		ll tmp; cin>>tmp;

		mi = min(mi,tmp);

		d[i] =tmp;
	}

	if((n-mi)%mi && n >mi){
		writeln(5+1+(n-mi)/mi);
	}else {
		writeln(5+(n-mi)/mi);
	}


}

