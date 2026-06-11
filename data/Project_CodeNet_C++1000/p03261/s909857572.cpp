#include <bits/stdc++.h>
using namespace std;

int main(){
	int N;
	cin >> N;
	vector<string> S;
	bool f=true;
	string bf;
	for(int i=0; i<N; i++){
		string s; cin >> s;
		auto itr = find(S.begin(),S.end(),s);
		if(i && s[0] != bf[bf.size()-1]){ f=false; }
		if(itr != S.end()){ f=false; }
		S.push_back(s);
		bf = s;
	}
	if(f)cout << "Yes" << endl;
	else cout << "No" << endl; 
	return 0;
}