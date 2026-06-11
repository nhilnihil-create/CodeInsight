#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;cin>>n;
	string s;cin>>s;
	int cnt1[26];
	int cnt2[26];
	memset(cnt1,0,sizeof cnt1);
	memset(cnt2,0,sizeof cnt2);
	for(int i=0;i<n;i++){
		cnt1[s[i]-'a']++;
	}
	int mx=0;
	for(int i=0;i<n;i++){
		int now=0;
		cnt2[s[i]-'a']++;
		cnt1[s[i]-'a']--;
		for(int j=0;j<26;j++){
			if(cnt1[j]&&cnt2[j])now++;
		}
		mx=max(mx,now);
	}
	cout<<mx;
	return 0;
}