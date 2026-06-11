#include<bits/stdc++.h>
using namespace std;

const long long INF = 1000000000;

typedef long long ll;

#define writeln(n) cout<<n<<"\n"
#define rep(i,n) for(int i=0; i<(n); ++i)

typedef pair<int, int> P;
typedef pair<string, int> Psi;

int d[5];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n;cin>>n;

	 rep(i,n){
		 string s;cin>>s;

		 if(s[0] =='M'){
			 d[0]++;
		 }else if (s[0] =='A') {
			 d[1]++;
		}else if (s[0] =='R') {
			d[2]++;
		}else if (s[0] =='C') {
			d[3]++;
		}else if(s[0] =='H'){
			d[4]++;
		}
	 }

	 ll ans=0;
	 rep(i,5){
		 for(int j =i+1; j<5; j++){
			 for(int k= j+1; k<5; k++){
				ans += (ll)d[i]*d[j]*d[k];
			 }
		 }
	 }

	 writeln(ans);



}
