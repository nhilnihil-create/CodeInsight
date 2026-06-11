#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007, INF=mod*mod*3LL;
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int h, w, n;
    cin >> h >> w >> n;
    int ans = h, nowx = 0, nowy = 0, x, y;
    vector<set<int> > s(w, {114514810});
    for(int i=0;i<n;i++){
    	cin >> x >> y;
    	x--; y--;
    	s[y].insert(x);
    }
    while(nowx < h){
    	ans = min(ans, *s[nowy].upper_bound(nowx));
    	nowx++; nowy++;
    	if(nowy >= w) break;
    	while(s[nowy].count(nowx)) nowx++;
    }
    cout << ans << endl;
    return 0;
}
