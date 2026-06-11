#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(int)(n); i++)

using namespace std;
typedef long long LL;
typedef pair<int,int> P;
const int Max_Num=1e5+10;

int main(){
	int n;
	cin >> n;
	vector<int> v(n);
	rep(i,n) cin >> v[i];
	map<int,int> odd, even;
	rep(i,n){
		if(i%2==0) odd[v[i]]++;
		else even[v[i]]++;
	}
	vector<P> o, e;
	for(auto itr:odd) o.emplace_back(P(itr.second,itr.first));
	for(auto itr:even) e.emplace_back(P(itr.second,itr.first));
	o.emplace_back(0,0), e.emplace_back(0,0);
	sort(o.begin(),o.end(),greater<P>());
	sort(e.begin(),e.end(),greater<P>());
	if(o[0].second==e[0].second){
		cout << min(n-o[0].first-e[1].first,n-o[1].first-e[0].first) << endl;
	}
	else cout << n-o[0].first-e[0].first << endl;

	return 0;
}