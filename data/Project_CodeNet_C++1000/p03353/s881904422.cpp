#include<bits/stdc++.h>

using namespace std;

int
main(void){	
	string s; int k;
	cin >> s;
	cin >> k;
	vector<string> vec;
	for(int i = 0; i < s.size(); i++){
		string ins = "";
		for(int j = i; j < min(i + 5, (int)s.size()); j++){
			ins += s[j];
			vec.push_back(ins);
			//cout << ins << "\n";
		}
	}
	vector<string> ans;
	sort(vec.begin(), vec.end());
	ans.push_back(vec[0]);
	for(int i = 1; i < vec.size(); i++){
		if(vec[i] != vec[i - 1])
			ans.push_back(vec[i]);
	}
	cout << ans[k - 1];
	//cout << vec[k - 1];
}