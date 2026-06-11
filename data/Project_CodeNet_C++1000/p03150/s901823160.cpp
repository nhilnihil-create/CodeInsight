#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const int inf = 1e9;
const ll INF = 1e18;
const double pi = 3.14159265358979323846;
#define rep(i,n) for(ll i=0;i<n;i++)

int main(){
	string s;cin>>s;
	string ss="keyence";
	int n=s.size();
	if(s==ss){
		cout<<"YES"<<"\n";
		return 0;
	}
	rep(i,n){
		for(int j=i;j<n;j++){
			string t="";
			for(int k=0;k<n;k++){
				if(i<=k&&k<=j) continue;
				else t+=s[k];
			}
			//cout<<t<<"\n";
			if(ss==t){
				cout<<"YES"<<"\n";
				return 0;
			}
		}
	}
	cout<<"NO"<<"\n";
}