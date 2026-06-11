#include <bits/stdc++.h>
using namespace std;
#define modulo 998244353
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 100000000000000000



int main(){
	
	string S;
	cin>>S;
	
	int ans = S.size();
	
	for(int i=0;i<S.size()-1;i++){
		if(S[i]==S[i+1])continue;
		int k = max(i+1,(int)S.size()-(i+1));
		ans = min(k,ans);
	}
	
	cout<<ans<<endl;
	
    return 0;
}
