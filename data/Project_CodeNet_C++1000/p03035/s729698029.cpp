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

	int a,b;cin>>a>>b;
	
	if(a >=13){
		writeln(b);
	}else if (a>=6) {
		writeln(b/2);
	}else {
		writeln(0);
	}


}
