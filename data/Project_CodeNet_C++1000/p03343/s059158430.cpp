#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
#define llint long long
#define inf 1e9

using namespace std;
typedef pair<llint, llint> P;

llint n, k, q;
llint a[2005];
vector<P> vec;
bool used[2005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k >> q;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		vec.push_back(P(a[i], i));
	}
	sort(vec.begin(), vec.end());
	
	used[0] = used[n+1] = true;
	
	llint ans = inf;
	for(int t = 0; t < vec.size(); t++){
		
		llint l = 0;
		vector<llint> tmp, tmp2;
		for(int i = 1; i <= n+1; i++){
			if(used[i]){
				tmp2.clear();
				for(int j = l+1; j < i; j++) tmp2.push_back(a[j]);
				sort(tmp2.begin(), tmp2.end());
				if(tmp2.size() >= k){
					for(int j = 0; j < (int)tmp2.size()-k+1; j++) tmp.push_back(tmp2[j]);
				}
				l = i;
			}
		}
		sort(tmp.begin(), tmp.end());
		
		if(tmp.size() >= q){
			ans = min(ans, tmp[q-1] - tmp.front());
		}
		used[vec[t].second] = true;
	}
	cout << ans << endl;
	
	return 0;
}