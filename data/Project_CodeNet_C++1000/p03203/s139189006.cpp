#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;
int x[200010],y[200010];
vector<int> v[200010];
set<int> st[200010];
int main(){
	int i,h,w,n,ans = 200010;
	cin >> h >> w >> n;
	for(i=0;i<n;i++){
		cin >> x[i] >> y[i];
		v[y[i]].push_back(x[i]);
		st[y[i]].insert(x[i]);
	}
	for(i=1;i<=h;i++){
		sort(v[i].begin(),v[i].end());
		v[i].push_back(h+1);
	}
	int s = 1,t = 1,res = 0;
	for(i=1;i<=h;i++){ 
		auto it = upper_bound(v[t].begin(),v[t].end(),s);
		int k = *it;
		ans = min(ans,res + k - s);
		if(k==s+1) break;
		s++;
		if(!st[t+1].count(s) && t<w) t++;
		res++;
	}
	cout << ans << endl;
}