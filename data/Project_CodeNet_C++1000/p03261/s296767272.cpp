#include <bits/stdc++.h>

#define ll long long 
#define sz(x) (int)x.size()

using namespace std;

int main(){
	int n;
	cin>>n;
	map<string,int>m;
	char last;
	bool ok=1;
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		if(m[s]){
			ok=0;
		}
		if(i){
			if(last!=s[0])ok=0;
		}	
		last=s[sz(s)-1];
		m[s]++;
	}
	cout<<(ok?"Yes":"No");
}