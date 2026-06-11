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

	string s; cin>>s;

	ll k; cin>>k;

	if( k-1<s.length()){
		if(s[k-1] =='1'){
		bool judge =true;
		rep(i, k){
			if(s[i] != '1'){
				judge =false;
				break;
			}
		}
		if(judge){writeln(1);
		return 0;
		}
		}
	}

	rep(i,s.length()){
		if(s[i] != '1'){
			writeln(s[i]);
			return 0;
		}
	}


}
