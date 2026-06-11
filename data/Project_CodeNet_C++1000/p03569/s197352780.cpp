#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main() {
	string s;
	cin>>s;
	ll l=0,r=s.size()-1,ans=0;
	while(l<r){
		if(s[l]==s[r]){
			l++;
			r--;
		}else{
			if(s[l]=='x'){
				l++;
				ans++;
			}
			else if(s[r]=='x'){
				r--;
				ans++;
			}
			else{
				cout<<-1<<"\n";
				return 0;
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}