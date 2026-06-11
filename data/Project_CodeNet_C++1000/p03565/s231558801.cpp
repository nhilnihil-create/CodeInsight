#include <algorithm>
#include <cmath>
#include <vector>
#include <functional>
#include <cstdlib>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <ctype.h>
#include <climits>
#include <queue>
#include <iomanip>
using namespace std;
typedef long long ll;
#define REP(i, n) for(ll i = 0; i < (ll)(n); ++i)
template<class T> inline bool chmax(T& a, T b) { if(a < b){ a=b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if(a > b){ a=b; return 1; } return 0;}

int main(){
	string s,t;
	cin >> s >> t;
	
	vector<string> ans;
	REP(k,(int)s.size()-(int)t.size()+1){
		string a = string((int)s.size(), '.');
		bool ok = true;
		for(int i=0; i<(int)s.size();i++){
			if(i<k || k+(int)t.size()<=i){
				if(s[i]=='?') a[i] = 'a';
				else a[i] = s[i];	
			}else if(k<=i && i<k+(int)t.size()){
				if(s[i]=='?'){
					a[i] = t[i-k];
				}else if(s[i]==t[i-k]){
					a[i] = t[i-k];
				}else{
					ok = false;
					break;
				}
			}
		}
		if(ok) ans.push_back(a);
	}
	
	if(ans.size()==0){
		cout << "UNRESTORABLE\n";
		return 0;
	}
	
	sort(ans.begin(),ans.end());
	
	cout << ans[0] << endl;
	
	return 0;
}