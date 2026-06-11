#include<bits/stdc++.h>
#define ll long long
#define all(a) a.begin(),a.end()
#define sz(a) a.size()
#define re return 
#define MP make_pair
#define pb push_back
#define pii pair<int,int>
#define se second
#define fi first
using namespace std;
char s[100005],cmp1[100005],cmp2[100005];
int ans1,ans2;
signed main(){
	ios_base::sync_with_stdio(0);
	cin>>s;
	int len=strlen(s);
	for(int i=0;i<len;i++){
		if(i%2) cmp1[i]='1',cmp2[i]='0';
		else cmp1[i]='0',cmp2[i]='1';
	}
	for(int i=0;i<len;i++){
		if(s[i]!=cmp1[i]) ans1++;
		if(s[i]!=cmp2[i]) ans2++;
	}
	cout<<min(ans1,ans2);
	re 0;
}
