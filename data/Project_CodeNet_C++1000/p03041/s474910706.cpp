#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll n,k;
	cin>>n>>k;
	k--;
	string s;
	cin>>s;
	for(ll i=0;i<n;i++){
		if(i==k){
			cout << char(s[i]-'A'+'a');
		}
		else{
			cout <<s[i];
		}
	}
	// your code goes here
	return 0;
}