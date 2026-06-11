#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long; 

ll n;
vector<int> a;
int cnt;

void dfs2(bitset<3> bt, ll num){
	if(num > n) return;
  	if(bt.test(0) && bt.test(1) && bt.test(2)) cnt++;
  	
  	rep(i,3){
    	bitset<3> tmp = bt;
      	tmp.set(i,1);
      	dfs2(tmp, num*10+a.at(i));
    }
  	
  	return;
}

void dfs(){
	rep(i,3){
    	bitset<3> bt("000"); bt.set(i,1);
      	dfs2(bt,a.at(i));
    }
}

int main(){
	cin >> n;
  	a = vector<int>(3);
  	a.at(0) = 3;
  	a.at(1) = 5;
  	a.at(2) = 7;
  	cnt = 0;
  	dfs();
  	cout << cnt << endl;
}