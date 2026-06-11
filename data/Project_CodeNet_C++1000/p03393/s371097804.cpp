#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using v  = vector<ll>;
#define rep(i,n) for(ll i=0;i<(n);i++)

char nxt(string s,char i){
	if(i> 'z') return '\n';
	return s.find(i)==string::npos ? i : nxt(s,i+1); 
}

int main(){
    string s; cin >> s;
	auto t = s;
	if(s.size() <26) {
		cout << s << nxt(s,'a');
		return 0;
	}
	if(next_permutation(s.begin(),s.end())){
		int c =0;
		for(c=0;s[c]==t[c];c++) cout <<s[c];
		cout << s[c];
	}else{
		cout << -1;
	}

  	return 0;
}