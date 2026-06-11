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

	string s, t;
	cin>>s>>t;
	vector<int> p(26, -1);
	int n = s.size();
	for(int i = 0; i < n; i++){
		int cs = s[i] - 'a';
		int ct = t[i] - 'a';
		if(p[cs] == -1){
			p[cs] = ct;
		}
		if(p[cs] != ct){
			cout<<"No"<<endl;
			exit(0);
		}
	}
	set<int> st;
	for(int i = 0; i < 26; i++){
		if(p[i] != -1 && st.find(p[i]) != st.end()){
			cout<<"No"<<endl;
			exit(0);
		}
		if(p[i] != -1)st.insert(p[i]);
	}
	cout<<"Yes"<<endl;

	return 0;
}