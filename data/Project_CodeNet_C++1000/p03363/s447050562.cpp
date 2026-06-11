#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
int main(){
	int n;	cin >> n;
  	vector<int64_t> a(n);	rep(i,n) cin >> a.at(i);
  	
  	vector<int64_t> sm(n+1,0);
	rep(i,n) sm.at(i+1) = sm.at(i) + a.at(i);
// 	rep(i,n+1) cout << sm.at(i) << endl;

	map<int64_t,int64_t> mp;
  	rep(i,n+1) mp[sm.at(i)] += 1;
  	int64_t sum = 0;
  	for(auto i:mp){
      	int64_t tmp = i.second;
    	sum += (tmp-1)*tmp/2;
    }
  	cout << sum << endl;
}
