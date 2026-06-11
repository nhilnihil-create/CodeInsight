#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=0;i<(n);++i)
constexpr int mod=1000000007;
constexpr int mod1=998244353;
vector<int> dx={0,-1,0,1},dy={1,0,-1,0};
bool inside(int y,int x,int h,int w){
	if(y<h && y>=0 && x<w && x>=0) return true;
	return false;
}


vector<string> t{"KIHBR","AKIHBR","KIHABR","AKIHABR","KIHABAR","AKIHABAR","KIHBAR","AKIHBAR","KIHABARA","AKIHABARA","KIHBRA","AKIHBRA","KIHABRA","AKIHABRA","KIHBARA","AKIHBARA"};


int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	string s;cin >> s;
	bool ok = false;
	rep(i,t.size()){
		if(s == t.at(i)) ok = true;
	}
	cout << (ok ? "YES" : "NO") << endl;
}
