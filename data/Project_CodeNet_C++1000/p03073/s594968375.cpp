#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;

int main(){
	
	string s; cin>>s;
	int cnt1{},cnt2{};
	for(int i=0; i<s.size(); i++){
		if(s.at(i)=='0'+i%2) cnt1++;
		if(s.at(i)=='1'-i%2) cnt2++;
	}
	cout << min(cnt1,cnt2)<<endl;
	
	
}