#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a;
long long l = 0, r = 1e18;
typedef pair<int, long long> P;

int main(){
//	cin.tie(0);
//	ios::sync_with_stdio(false);
	cin >> n;
	a.resize(n);
	for(int i=0; i<n; ++i) cin >> a[i];
	while(l+1<r){
//		cout << l << " " << r << "\n";
		long long m = (l+r)/2;
//		m = 1;
		priority_queue<P> q; // last digit or non-zero digit
		q.push(P(a[0], 0));
		bool f = true;
		for(int i=1; i<n; ++i){
			if(a[i] > a[i-1]){
				if(q.top().second == 0) q.pop();
				q.push(P(a[i], 0));
				continue;
			}
			while(!q.empty() && q.top().first > a[i]) q.pop();
			if(q.empty() || q.top().first < a[i]){
				q.push(P(a[i], 1));
				if(m == 1){
					f = false;
					break;
				}
				continue;
			}
			P p = q.top();
			q.pop();
			++p.second;
			if(p.second == m){
				int t = p.first - 1;
				bool g = true;
				while(!q.empty() && q.top().first == t){
					if(q.top().second == m-1){
						q.pop();
						--t;
					}else{
						P tmp = q.top();
						q.pop();
						++tmp.second;
						q.push(tmp);
						g = false;
//						cout << "t " << tmp.first << " " << tmp.second << "\n";
						break;
					}
				}
				if(t == 0){
					f = false;
					break;
				}
				if(g){
					if(m == 1){
						f = false;
						break;
					}
					q.push(P(t, 1));
				}
				p.second = 0;
			}
			q.push(p);
/*			cout << i+1 << " " << "\n";
			vector<P> v;
			while(!q.empty()){
				cout << q.top().first << " " << q.top().second << "\n";
				v.push_back(q.top());
				q.pop();
			}
			for(P j : v) q.push(j);
*/		}
//		break;
		if(f) r = m;
		else l = m;
	}
	cout << r << "\n";
}