#include<bits/stdc++.h>
using namespace std;
#define fastIO ios::sync_with_stdio(0), cin.tie(0)
#define all(x) (x).begin() (x).end()
#define rall(x) (x).rbegin() (x).rend()
typedef pair<int,int> pii;
typedef long long ll;

void A(){
	/**int m,p; cin>>m>>p;
	cout<<((m*3)+p)/2<<endl;*/
}

bool cmp(pair<string,pair<int, int>> &a, pair<string,pair<int, int>> &b){
	if(a.first==b.first)return (a.second.first > b.second.first); 
	else return a.first<b.first;
}
int main(){
	int r, score; cin>>r;
	vector<pair<string, pair<int, int>>> v; 
	for(int i=0; i<r; i++){
		string s; cin>>s>>score;
		v.push_back({s, {score, i+1}});
	}
	sort(v.begin(), v.end(), cmp);
	for(auto&x: v){
		cout<<x.second.second<<endl;
	}
	return 0;
}
