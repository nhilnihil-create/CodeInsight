#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(int)(n); i++)

using namespace std;
typedef long long LL;
typedef pair<int,int> P;

int main(){
	int N, M;
	cin >> N >> M;
	if(N==1){
		cout << M << endl;
		return 0;
	}
	int ans=1;
	for(int i=2; i*i<=M; i++){
		if(N*i>M) break;
		if(M%i==0){
			if(i<N) ans=max(ans,i);
			else ans=max(ans,M/i);
		}
	}
	cout << ans << endl;

	return 0;
}