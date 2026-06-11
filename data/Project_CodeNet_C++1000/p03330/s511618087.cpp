#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long ll;
typedef pair<ll,ll> P;
const ll mod=1000000007;
const ll LINF=1LL<<60;
const int INF=1<<30;

int n,c;

vector<vector<int>> d(30+1,vector<int>(30+1));
vector<int> mod0(30 + 1,0);
vector<int> mod1(30 + 1,0);
vector<int> mod2(30 + 1,0);

ll calc(int x,int y,int z){
	ll ans = 0;
	for(int i = 1; i <=c; i++) {
		ans += mod0[i] * d[i][x];
		ans += mod1[i] * d[i][y];
		ans += mod2[i] * d[i][z];
	}
	return ans;
}

int main(){
	cin>>n>>c;

	for(int i = 1; i <= c; i++) {
		for(int j = 1; j <=c; j++) {
			cin>>d[i][j];
		}
	}

	
	int x;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			cin>>x;
			if ((i + j) % 3 == 0){
				mod0[x]++;		
			}
			else if ((i + j) % 3 == 1){
				mod1[x]++;
			}
			else{
				mod2[x]++;
			}
		}
	}
	ll ans = LINF;
	for(int i = 1; i <= c; i++) {
		for(int j = 1; j <= c ; j++) {
			for(int k = 1; k <= c; k++) {
				if (i != j && j != k && i != k){
					ans = min(ans,calc(i,j,k));
				}
			}
		}
	}
	cout << ans << endl;



	return 0;
}