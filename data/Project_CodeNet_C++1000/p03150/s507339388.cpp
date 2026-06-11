#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define F first
#define S second
#define PB push_back
#define MK make_pair
#define REP(i, a, b) for (int i=a; i < b; i++)


bool sort_by(pi c, pi d){
	return c.S < d.S;
}

int main() {
	string S, ans="NO", keyence = "keyence";
	cin >> S;
	int lk = (int)keyence.size();
	int ls = 0, lr=0;
	while(ls < lk && S[ls] == keyence[ls]) ++ls;
	
	reverse(keyence.begin(), keyence.end());
	reverse(S.begin(), S.end());
	if(ls != lk){
		while(lr < lk && S[lr] == keyence[lr]) ++lr;
		//cout << " " << lr << " " << l << endl;
		if(lr+ls >= lk) ans = "YES";
	}
	else ans = "YES";
	
	cout << ans;



}
