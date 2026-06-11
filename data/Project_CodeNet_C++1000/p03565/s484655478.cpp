#include <bits/stdc++.h>
using namespace std;

#define int long long
#define forn(i,a,n) for (int i=a; i<n; i++)

signed main(){
	ios::sync_with_stdio(false);
   	cin.tie(0);

	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);

	string s,t,res;
	cin>>s>>t;
	reverse(s.begin(),s.end());
	reverse(t.begin(),t.end());
	forn(i,0,s.size()-t.size()+1){
		bool re=1;
		string ans=s;
		forn(j,0,t.size()){
			if (s[i+j]==t[j] || s[i+j]=='?'){
				ans[i+j]=t[j];
				continue;
			}
			re=0;
			break;
		}
		if (!re) continue;
		forn(j,0,ans.size())
			ans[j]=(ans[j]=='?'?'a':ans[j]);
		reverse(ans.begin(),ans.end());
		if (res=="" || res>ans)
			res=ans;
	}
	if (res=="")
		res="UNRESTORABLE";
	cout<<res<<endl;
	return 0;
}