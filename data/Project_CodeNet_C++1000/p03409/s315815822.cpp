#include <bits/stdc++.h>
using namespace std;

typedef pair<long long, long long> pi;
typedef pair<pi, bool> pii;

long long n, c, x, y;
pii a[2000000];
set<long long> s;
set<long long>::iterator it;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> x >> y;
		a[i] = pii(pi(x, y), 0);
	}
	for(int i = 0; i < n; i++){
		cin >> x >> y;
		a[i+n] = pii(pi(x, y), 1);
	}
	sort(a, a+(2*n));
	for(int i = 0; i < 2*n; i++){
		if(!a[i].second) s.insert(a[i].first.second);
		else {
			it = s.lower_bound(a[i].first.second);
			if(it != s.begin()){
				it--;
				c++;
				s.erase(it);
			}
		}	
	}
	cout << c;
}