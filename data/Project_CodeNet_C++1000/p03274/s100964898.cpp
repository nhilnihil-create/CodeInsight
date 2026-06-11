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

	vector<int> a,b;
	a.push_back(0);
	b.push_back(0);

	rep(i,n){
		int tmp;cin>>tmp;

		if(tmp<0){
			b.push_back(tmp);
		}else {
			a.push_back(tmp);
		}
	}
	sort(a.begin(),a.end());
	sort(b.begin(),b.end(),greater<int>());

	ll ans = 10000000000000;
	for(int i=0; i<b.size(); i++){
		int sum =0;
		sum  = abs(b[i]);

		if(a.size()-1 >= k-i){
			sum += abs(a[k-i]);

			sum += min(abs(b[i]),abs(a[k-i]));

			ans = min(ans, (ll)sum);
			/*cout<<i<<" "<<k-i<<" "<<sum<<endl;*/
		}
	}

	writeln(ans);



}

