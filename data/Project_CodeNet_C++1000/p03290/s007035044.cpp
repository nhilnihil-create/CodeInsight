#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(int)(n); i++)

using namespace std;
const int INF=1e5;

int main(){
	int D, G;
	cin >> D >> G;
	vector<int> p(D), c(D);
	rep(i,D) cin >> p[i] >> c[i];
	int ans=INF;
	rep(bit,1<<D){
		int score=0, res=0;
		rep(i,D){
			if(bit&1<<i){
				score+=c[i];
				score+=100*(i+1)*p[i];
				res+=p[i];
			}
		}
		int rem=G-score;
		if(rem<=0){
			ans=min(ans,res);
			continue;
		}
		for(int i=D-1; i>=0; i--){
			if(bit&1<<i) continue;
			int s=100*(i+1);
			if(rem<=s*p[i]){
				res+=(rem+s-1)/s;
				ans=min(ans,res);
				break;
			}
			else{
				res+=p[i];
				rem-=s*p[i];
			}
		}
	}
	cout << ans << endl;

	return 0;
}