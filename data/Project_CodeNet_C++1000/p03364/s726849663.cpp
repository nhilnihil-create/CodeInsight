#include <bits/stdc++.h>
using namespace std;

int main(){
	int N;
	cin >> N;
	vector<string> S(N);
	for(auto &i:S)cin >> i;
	
	int ans=0;
	for(int k=0;k<N;k++){
		bool flag=true;
		for(int i=0;i<N;i++)for(int j=i+1;j<N;j++){
			if(S[i][(j-k+N)%N]!=S[j][(i-k+N)%N])flag=false;
		}
		if(flag)ans+=N;
	}
	cout << ans << endl;
	return 0;
}