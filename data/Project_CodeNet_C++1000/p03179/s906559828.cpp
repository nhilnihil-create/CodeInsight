#include<bits/stdc++.h>
#define ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define debug  freopen("in.txt","r",stdin),freopen("out.txt","w",stdout);
#define fs first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxn = 1e6+10;
const int mod = 1e9+7;
using namespace std;

int N;
string s;
ll f[3030][3030];

void solve(){
	f[1][1] = 1;
	for(int i = 2;i<=N;i++){
		if(s[i-1] == '<'){
			for(int j = 1;j<=i;j++){
				f[i][j] = f[i][j-1] + f[i-1][j-1]; f[i][j] %= mod;
			}
		}else{
			for(int j = i;j>=1;j--){
				f[i][j] = f[i][j+1] + f[i-1][j]; f[i][j] %= mod;
			}
		}
	}
	ll ans = 0;
	for(int i = 1;i<=N;i++) ans = (ans + f[N][i]) %mod;
	cout<<ans<<'\n';
}

int main(){
    // debug;
    ios;

    cin>>N;
    cin>>s; 
    s = '#' + s;
    solve();
    
    return 0;
}
