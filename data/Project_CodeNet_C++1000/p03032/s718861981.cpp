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

	vector<ll> V(n);

	rep(i, n){
		cin>>V[i];
	}
	ll ans =0;
	for(int i=0; i<= min(n,k); i++){
		for(int j=0; i+j<=min(n,k); j++){

			vector<ll> s;
			ll  sum=0;
			for(int p=0 ; p<i; p++){
				s.push_back(V[p]);
				sum += V[p];
			}
			for(int p=0 ; p<j; p++){
				s.push_back(V[n-1-p]);
				sum += V[n-1-p];
			}
			sort(s.begin(),s.end());
			for(int p =0; p<min((k-i-j),(int)s.size()); p++){
				if(s[p] <0) sum-=s[p];
			}

			ans = max(ans,sum);
		}
	}

	writeln(ans);


}
