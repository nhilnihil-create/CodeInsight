#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
	int N; string S; cin>>N>>S;
	int ans=0;
	for(int i=0;i<N;i++){
		map<char,int> se1,se2;
		for(int j=0;j<N;j++){
			if(j<i){
				se1[S[j]]=1;
			}else{
				se2[S[j]]=1;
			}
		}
		int tmp=0;
		for(auto p : se1){
			tmp+=min(p.second,se2[p.first]);
		}
		ans=max(ans,tmp);
	}
	cout<<ans<<endl;
}