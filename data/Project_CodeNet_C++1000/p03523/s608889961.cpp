#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric>
#include <set>
#include <cstdlib>
#include <queue>

using namespace std;

typedef long long llint;
typedef long double ld;
#define inf 1e18

priority_queue<int,vector<int>,greater<int>> que;


llint b;
bool f=0;
void dfs(string s,int i){
	if(s=="AKIHABARA"){
		f=1;
		return;
	}
	if(i>s.size()) return;
	dfs(s,i+1);
  s.insert(s.begin()+i,'A');
  dfs(s,i+2);
}
void solve(){
	string s;
	cin >> s;
	if(s.size()>9){
    cout<<"NO"<<endl;
  }
	else{
  	dfs(s,0);
  	if(!f) cout<<"NO"<<endl;
  	else cout<<"YES"<<endl;
	}
}

int main(int argc, char *argv[]) {
  solve();
  return 0;
}
