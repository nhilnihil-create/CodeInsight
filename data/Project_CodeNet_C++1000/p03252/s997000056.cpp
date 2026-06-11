#include<iostream>
#include<iomanip>
#include<functional>
#include<algorithm>
#include<string>
#include<vector>
#include<utility>
#include<tuple>
#include<map>
#include<set>
#include<queue>
#include<cmath>

using namespace std;
#define LL long long

string s,t;
vector<char>sal[30],tal[30];
bool flg=true;

int main() {
	cin>>s>>t;
	for(int i=0;i<s.size();i++){
		sal[s[i]-'a'].push_back(t[i]);
		tal[t[i]-'a'].push_back(s[i]);
	}
	for(int i=0;i<30;i++){
		sal[i].erase(unique(sal[i].begin(),sal[i].end()),sal[i].end());
		tal[i].erase(unique(tal[i].begin(),tal[i].end()),tal[i].end());
		if(sal[i].size()>1||tal[i].size()>1)flg=false;
	}
	cout<<(flg?"Yes":"No")<<endl;
	return 0;
}

