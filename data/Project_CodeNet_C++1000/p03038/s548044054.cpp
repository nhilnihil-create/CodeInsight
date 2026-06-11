#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 123;
#define int long long 
int n, m;
pair <int, int> a[maxn];
string s, t;
main () { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;   
    multiset <int> q;
    for(int i = 1; i <= n; i++) {
    	int x;
    	cin >>x;
    	q.insert(x);
    }

    for(int i = 1; i <= m; i++) {
    	cin >> a[i].second >> a[i].first;
    }

    sort(a + 1, a + m + 1);
    reverse(a + 1, a + m + 1);

    for(int i = 1; i <= m; i++) {
    	while(*q.begin() < a[i].first && a[i].second){
    		int x = *q.begin();
    		q.erase(q.find(x));
    		q.insert(a[i].first);
    		a[i].second--;
    	}
    }
    int ans = 0;
    while(q.size()) {
    	int x = *q.begin();
    	ans += x;
    	q.erase(q.find(x));
    }
    cout <<ans;
}


