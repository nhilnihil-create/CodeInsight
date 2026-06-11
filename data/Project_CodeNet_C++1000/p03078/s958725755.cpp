#include<bits/stdc++.h>
using namespace std;

const long long INF = 1000000000;

typedef long long ll;

#define writeln(n) cout<<n<<"\n"
#define rep(i,n) for(int i=0; i<(n); ++i)

typedef pair<int, int> P;
typedef pair<string, int> Psi;


vector<ll> A(1010),B(1010),C(1010);



int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);


	int x,y,z,k;cin>>x>>y>>z>>k;

	rep(i,x){
		cin>>A[i];
	}
	rep(i,y){
		cin>>B[i];
	}
	rep(i,z){
		cin>>C[i];
	}

	sort(A.begin(),A.end(),greater<ll>());
	sort(B.begin(),B.end(),greater<ll>());
	sort(C.begin(),C.end(),greater<ll>());

	vector<ll> ans;

	for(int i=0; i<x; i++){
		for(int j=0; j<y; j++){
			for(int l=0; l<z; l++){
				if((i+1)*(j+1)*(l+1) > k)break;
				ans.push_back(A[i]+B[j]+C[l]);


			}
		}
	}
	sort(ans.begin(),ans.end(),greater<ll>());

	rep(i,k){
		writeln(ans[i]);
	}
}

