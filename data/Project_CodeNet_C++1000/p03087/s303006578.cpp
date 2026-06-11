#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;

int main(){
	
	int n,q; string s;
	cin>>n>>q>>s;
	vector<int> a(n+1);
	for(int i=2; i<n+1; i++){
		a.at(i)=a.at(i-1);
		if(s.at(i-2)=='A'&&s.at(i-1)=='C'){
			a.at(i)++;
		}
	}
	for(int i=0; i<q; i++){
		int l,r; cin>>l>>r;
		l--; r--;
		if(l==0) cout << a.at(r+1)<<endl;
		else if(s.at(l-1)=='A'&&s.at(l)=='C'){
			cout << a.at(r+1)-a.at(l)-1<<endl;
		}
		else cout << a.at(r+1)-a.at(l)<<endl;
	}
	
}