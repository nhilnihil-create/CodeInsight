#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const int inf = 1e9;
const ll INF = 1e18;
const double pi = 3.14159265358979323846;
#define rep(i,n) for(ll i=0;i<n;i++)

int main(){
	int n;string s;cin>>n>>s;
	int alpha[26]={};
	rep(i,n) alpha[s[i]-'a']++;
	ll sum=1;
	rep(i,26) sum=(alpha[i]+1)*sum%MOD;
	cout<<sum-1<<"\n";
}