#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define repp(i,a,b) for(int i = (int)(a) ; i < (int)(b) ; ++i)
#define repm(i,a,b) for(int i = (int)(a) ; i > (int)(b) ; --i)

int main(){
	int L; cin >> L;
	vector<pair<int,int>> V;
	while((1<<18) <= L){
		L -= (1<<18);
		V.push_back(make_pair(2,L));
	}
	repm(i,17,-1) if((1<<i) <= L){
		L -= (1<<i);
		V.push_back(make_pair(20-i,L));
	}
	cout << 20 << ' ' << V.size()+36 << endl;
	for(auto u : V) cout << 1 << ' ' << u.first << ' ' << u.second << endl;
	repp(i,2,20){
		cout << i << ' ' << i+1 << ' ' << (1<<(19-i)) << endl;
		cout << i << ' ' << i+1 << ' ' << 0 << endl;
	}
	return 0;
}
