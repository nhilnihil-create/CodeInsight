#include <bits/stdc++.h>
 
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	string s;
	cin>>s;
	long long int size=s.size();
	long long int c1=0,c2=0;
	for(long long int i=0;i<s.size();i++){
		if(i&1){
			if(s[i]!='1'){
				c1++;
			}
		}
		else{
			if(s[i]!='0'){
				c1++;
			}
		}
	}
	for(long long int i=0;i<s.size();i++){
		if(i&1){
			if(s[i]!='0'){
				c2++;
			}
		}
		else{
			if(s[i]!='1'){
				c2++;
			}
		}
	}
	long long int ans=min(c1,c2);
	cout<<ans;
	return 0;
}