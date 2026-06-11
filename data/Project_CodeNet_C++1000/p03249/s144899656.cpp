#include <bits/stdc++.h>
using namespace std;
 
const int N = 100010;
typedef long long int64;
 
map<int64 , int> val;
int n , size[N] , fa[N];
 
int64 d[N];
typedef pair<int64 , int> pii;
priority_queue<pii> leaf;
#define mp make_pair 
 
int main() {
    cin >> n;
    for(int i = 1 ; i <= n ; ++i) {
        cin >> d[i];
        size[i] = 1;
        val[d[i]] = i; 
    }
    for(int i = 1 ; i <= n ; ++i) leaf.push(mp(d[i] , i));
	
	int64 root = 0;
    while(leaf.size()) {
        int x = leaf.top().second;
        leaf.pop();
 
		val.erase(d[x]);
        if(val.count(d[x] - n + size[x]*2))
            fa[x] = val[d[x] - n + size[x]*2];
        else break;
        
        size[fa[x]] += size[x];
        root += size[x];
    }
 
    for(int i = 1 , cnt = 0; i <= n ; ++i) {
    	if(fa[i] == 0 && (++cnt > 1 || d[i] != root))  {cout << -1 << endl; return 0;}
	}
    for(int i = 1 ; i <= n ; ++i)
        if(fa[i]) cout << i << ' ' << fa[i] << endl;
	
    return 0;
}