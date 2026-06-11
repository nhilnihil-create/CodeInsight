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
	int k; cin>>k;
	set<string> st;
	for(int i = 0; i < s.size(); i++){
		string t = "";
		for(int j = 0; j < k; j++){
			if(i + j >= s.size())break;
			t += s[i + j];
			st.insert(t);
		}
	}
	string ans;
	while(k--){
		ans = *st.begin();
		st.erase(ans);
	}
	cout<<ans<<endl;

	return 0;
}