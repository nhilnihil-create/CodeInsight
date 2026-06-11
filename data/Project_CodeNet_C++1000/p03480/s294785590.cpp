#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=0;i<(n);++i)

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	string s;cin >> s;
	int n=s.size();
	int inf=1000000000,ans=inf;
	rep(i,n-1){
		if(s.at(i)!=s.at(i+1)){
			ans=min(ans,max(i+1,n-i-1));
		}
	}
	if(ans==inf) cout << n << endl;
	else cout << ans << endl;
}