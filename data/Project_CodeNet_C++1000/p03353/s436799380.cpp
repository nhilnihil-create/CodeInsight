#include<bits/stdc++.h>

using namespace std;

string s;
int k;
vector<string> v;

string sub(int l, int r){
	return s.substr(l, r-l+1);
}

int main(){
	cin >> s >> k;
	
	for(int i = 0; i < s.size(); ++i){
		for(int j = 0; j < 5; ++j){
			if(i+j < s.size()){
				v.push_back(sub(i, i+j));
			}
		}
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	cout << v[k-1] << endl;
}