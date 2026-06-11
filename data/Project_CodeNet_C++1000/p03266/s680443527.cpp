#include<bits/stdc++.h>
using namespace std;

const long long INF = 1000000000;

typedef long long ll;

#define writeln(n) cout<<n<<"\n"
#define rep(i,n) for(int i=0; i<(n); ++i)

typedef pair<int, int> P;
typedef pair<string, int> Psi;



int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n,k;cin>>n>>k;

	if(k%2 ==0){

		ll a =n/k;
		ll b =(n+k/2)/k;

	writeln(a*a*a+b*b*b);
	}else {
		ll a =n/k;
		writeln(a*a*a);
	}



}

