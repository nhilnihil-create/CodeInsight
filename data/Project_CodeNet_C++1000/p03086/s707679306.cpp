#include <bits/stdc++.h>

#define forn(i,n) for(int i=0;i<n;i++)
#define sz(x) (int)x.size() 
typedef long long ll;
using namespace std;

int main() {
	string s;
	cin>>s;
	string pat="ACGT";
	int mx=0,cnt=0;
	forn(i,sz(s)){
		if(pat.find(s[i])!=pat.npos) cnt++;
		else cnt=0;
		mx=max(cnt,mx);
	}
	cout<<mx<<endl;
	return 0;
}