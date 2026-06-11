#include<bits/stdc++.h>
using namespace std;
#define LL long long

int main(){
	// sengen
	int n;
	// nyuryoku
	cin >> n;
	string s;
	int p;
	vector<pair<string,pair<int,int>>> v;
	for(int i=0;i<n;i++){
		cin >> s >> p;
		v.push_back({s,{-p,i+1}});
	}
	sort(v.begin(),v.end());
	// keisan
	for(auto x:v){
		cout << x.second.second << endl;
	}
	// syutsuryoku
}