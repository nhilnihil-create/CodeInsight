#include <bits/stdc++.h>
 
using namespace std;

const int N = 2e3+100, M = 4e6+10;

bitset<M> bt;

signed main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n;cin >> n;
	bt[0] = 1;
	for(int i=0 ; i<n ; i++){
		int d;cin >> d;
		bt |= (bt << d);
	}
	vector<int> v;
	for(int i=1 ; i<M ; i++)
		if(bt[i])
			v.push_back(i);
	int md = v.size()%2 == 0 ? v.size()/2-1 : v.size()/2;
	cout << v[md] << "\n";
 	return 0;
}














