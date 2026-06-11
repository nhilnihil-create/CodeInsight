#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const int inf = 1e9;
const ll INF = 1e18;
const double pi = 3.14159265358979323846;
#define rep(i,n) for(ll i=0;i<n;i++)

int main(){
	int alpha[26]={};
	string s;cin>>s;
	int l=s.size();
	rep(i,l) alpha[s[i]-'a']++;

	bool chk=0;int now=0;
	rep(i,26) {
		if(alpha[i]==0) {
			chk=1;
			now=i;
			break;
		}
	}
	if(chk){
		s=s+(char)('a'+now);
		cout<<s<<"\n";
	}
	else{
		for(int i=l-1;i>0;i--){
			if(s[i-1]<s[i]){
				string t=s.substr(0,i-1);
				//cout<<t<<"\n";
				char tt='z';
				for(int j=i;j<l;j++){
					if(s[i-1]<s[j]) tt=min(tt,s[j]);
				}
				t+=tt;
				cout<<t<<"\n";
				return 0;
			}
		}
		cout<<-1<<"\n";
		return 0;
	}
}