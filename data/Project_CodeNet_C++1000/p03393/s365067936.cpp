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
using namespace std;
typedef long long ll;
#define REP(i, n) for(ll i = 0; i < (ll)(n); ++i)
template<class T> inline bool chmax(T& a, T b) { if(a < b){ a=b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if(a > b){ a=b; return 1; } return 0;}

int main(){
	string s;
	cin >> s;
	
	int n = s.size();
	int alphabet[26] = {};
	REP(i,n){
		alphabet[(int)s[i]-(int)'a'] = 1;
	}
	
	REP(j,26){
		if(alphabet[j]==0){
			cout << s << (char)((int)'a'+j) << endl;
			return 0;
		}
	}
	for(int i=n-2; i>=0; --i){
		int now = (int)s[i]-(int)'a';
		int a[26] = {};
		for(int j=0; j<i; ++j){
			a[(int)s[j]-(int)'a'] = 1;
		}
		for(int k=now+1; k<26; ++k){
			if(a[k]==0){
				cout << s.substr(0,i) << (char)((int)'a'+k) << endl;
				return 0;
			}
		}
	}
	
	cout << "-1" << endl;
	
	return 0;
}
