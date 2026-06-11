#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;cin>>n;
	string s;cin>>s;

	int ans = 0;
	unordered_set<char> st;
	st.insert(s[0]);

	for(int i=1;i<n;i++){
		unordered_set<char> tt;
		
		for( int j=i;j<n;j++ )tt.insert(s[j]);
		
		int cnt = 0;
		
		for(auto it:tt){
		    if(st.find(it)!=st.end())cnt++;
		}
		
// 		ans=max((unsigned long)ans,min(tt.size(),st.size()));
        ans=max(ans,cnt);
		st.insert(s[i]);
	}
	cout<<ans<<endl;
	return 0;

}