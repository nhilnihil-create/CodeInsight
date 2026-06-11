#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

bool cmp(pair<string,pii> &a, pair<string,pii> &b){
	if(a.first==b.first)return (a.second.first > b.second.first); 
	else return a.first<b.first;
}

int main(){
	int t; cin>>t;
	vector<pair<string, pii>> v;
	for (int i = 0; i<t; i++){
		string s; cin>>s;
		int x; cin>>x;
		v.push_back({s,{x,i+1}});
	}
	sort(v.begin(), v.end(), cmp);
	for(auto&x: v){
		cout<<x.second.second<<endl;
	}
}
