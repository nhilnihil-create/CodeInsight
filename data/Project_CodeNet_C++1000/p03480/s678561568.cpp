#include<iostream>
#include<string>
#include<iomanip>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;

#define int long long
#define endl "\n"

const long long INF = (long long)1e18;
const long long MOD = (long long)1e9 + 7; 

string yn(bool f){return f?"Yes":"No";}
string YN(bool f){return f?"YES":"NO";}


int check(string &s, int k){
	vector<int> sum(s.size()+1, 0);
	
	if(k <= 0) return true;
	if(k > s.size()) return false;
	
	for(int i = 0; i < (int)s.size() - k + 1; i++){
		if((s[i] - '0' + sum[i])%2){
			sum[i]++;
			sum[i+k]--;
		}
		sum[i+1] += sum[i];
	}
	
	for(int i = (int)s.size() - k + 1; i < s.size(); i++){
		sum[i+1] += sum[i];
	}
	
	for(int i = 1; i < k; i++){
		if((s[i] - '0' + sum[i])%2) return false;
	}
	
	return true;
}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout<<fixed<<setprecision(10);
	
	string s;
	
	cin>>s;
	
	// for(int i = 1; i <= s.size(); i++){
		// cout<<check(s,i)<<endl;
	// }
	
	int l = 1, r = s.size()+1, m;
	
	while(l + 1 < r){
		m = (l+r)/2;
		
		if(check(s,m)){
			l = m;
		} else {
			r = m;
		}
	}
	
	cout<<l<<endl;
	
	return 0;
}