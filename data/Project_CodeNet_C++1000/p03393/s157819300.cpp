#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define until(x) while(!(x))
#define unless(x) if(!(x))
#define all(x) (x).begin(),(x).end()
#define F first
#define S second
#define pc __builtin_popcount

string s;

map<char,int> mp;

int32_t main(){
	cin>>s;
	int n = s.length();
	for(int i=0;i<n;i++){
		mp[s[i]]++;
	}
	char mex = 0;
	for(char c = 'a';c<='z';c++){
		if(!mp[c]){
			mex = c;
			break;
		}
	}
	if(!mex){
		mp.clear();
		string t = s;
		if(!next_permutation(all(s))){
			cout<<-1;
			return 0;
		}
		else {
			for(int i=0;i<s.length();i++){
				cout<<s[i];
				if(s[i]!=t[i]){
					return 0;
				}
			}
		}
	}
	cout<<s+mex;
}
