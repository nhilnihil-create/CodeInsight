#include <bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<string,string> P;
map<P,ll>num;

ll solution(int n,string s){
  ll ans = 0;
  string l, r;
  for(int i=0;i<(1<<n);++i){
		l="",r="";
		for(int j=0;j<n;++j){
			if(i>>j&1)l+=s[j];
			else r+=s[j];
		}
		num[P(l,r)]++;
	}
	for(int i=0;i<(1<<n);++i){
		l="",r="";
		for(int j=n-1;j>=0;--j){
			if(i>>j&1)l+=s[n+j];
			else r+=s[n+j];
		}
		ans+=num[P(r,l)];
	}
	return ans;
}

int main()
{
	int n = 2;
  cin>>n;
	string s = "abba";
  cin>>s;
	ll res = solution(n, s);
  cout<<res<<endl;
}
