#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007, INF=mod*mod*3LL;
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;
struct node{int from, to, dis;};
int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    int num = 0, m = N;
    while(m){
    	m /= 2;
    	num++;
    }
    int n = num;

    vector<vector<pair<int,int> > > v(n);
    for(int i=0;i<n-1;i++){
    	v[i].emplace_back(i+1, 0);
    	v[i].emplace_back(i+1, 1<<i);
    }
    vector<int> de;
    for(int i=0;i<20;i++){
    	de.pb(1 << i);
    }
    num = (1 << (n-1));
    while(N > num){
    	m = N - num;
    	int id = upper_bound(be(de), m) - de.begin() - 1;
    	v[id].emplace_back(n-1, num);
    	num += de[id];
    }
    vector<node> ans;
    for(int i=0;i<n;i++){
    	for(auto& j: v[i]){
    		ans.push_back({i + 1, j.first + 1, j.second});
    	}
    }
    cout << n << " " << ans.size() << endl;
    for(auto & i: ans){
    	cout << i.from << " " << i.to << " " << i.dis << endl;
    }
    return 0;
}
