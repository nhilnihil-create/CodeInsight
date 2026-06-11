#include <bits/stdc++.h>
typedef long long int ll;
using namespace std; 
int main(){
	ios_base::sync_with_stdio(false);  
	cin.tie(NULL);
	int n;cin>>n;
	int count1=0; int count2=0;
	int ans=0;int count3=0;ll ans1=0;
	for(int i=0;i<n;i++){
		string s;cin>>s;
		for(int i=0;i<s.length()-1;i++){
			if(s[i]=='A' && s[i+1]=='B'){
				ans1++;
			}
		}
		if(s[0]=='B' && s[s.length()-1]!='A'){
			count2++;
		}
		if(s[0]!='B' && s[s.length()-1]=='A'){
			count1++;
		}
		if(s[0]=='B' && s[s.length()-1]=='A'){
			count3++;
		}
	}	
	ans += max(0,count3-1);
	if(ans>0 || count3>0){
		if(count1>0){
			ans++;count1--;
		}
		if(count2>0){
			ans++; count2--;
		}
	}
	ans += min(count1,count2);
	cout<<ans1+ans<<endl;
}
