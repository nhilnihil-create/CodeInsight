#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long ll;
typedef pair<ll,ll> P;
const ll mod=1000000007;
const ll LINF=1LL<<60;
const int INF=1<<30;

int main(){
	string s;cin>>s;
	if (s.size() > 9){
		cout << "NO" << endl;
		return 0;
	}
	for(int bit = 0; bit < (1 << s.size() + 1); bit++) {
		string t = "";
		for(int i= 0; i <= s.size(); i++) {
			if((bit >> i) & 1){
				t += 'A';
			}
			if(i < s.size()){
				t += s[i];
			}
		}	
		if (t == "AKIHABARA"){
			cout << "YES" << endl;
			return 0;
		}														
	}
	cout << "NO" << endl;
	return 0;
}
