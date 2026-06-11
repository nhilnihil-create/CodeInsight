#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>s;
	int res=s.size();
	for(int i=1;i<s.size();i++){
		if(s[i]!=s[i-1]){
			res=min(res,max(i,(int)(s.size()-i)));
		}
	}
	cout<<min(res,(int)(s.size()))<<endl;
	return 0;
}
