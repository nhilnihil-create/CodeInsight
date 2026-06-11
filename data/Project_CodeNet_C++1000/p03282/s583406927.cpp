#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	string s;
	cin>>s;
	ll k; cin>>k; k--;
	for(int i = 0; i < s.size(); i++){
		if(s[i] != '1'){
			if(k < i){
				cout<<1<<endl;
			}else{
				cout<<s[i]<<endl;
			}
			exit(0);
		}
	}
	cout<<1<<endl;

	return 0;
}