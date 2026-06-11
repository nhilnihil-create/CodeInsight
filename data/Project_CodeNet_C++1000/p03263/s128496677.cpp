#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007, INF=(1LL<<60);
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

struct node{int a, b, c, d;};
int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int h, w;
    cin >> h >> w;
    int a[h][w];
    vector<node> v;
    for(int i=0;i<h;i++)for(int j=0;j<w;j++) cin >> a[i][j];
    for(int i=0;i<h;i++){
    	for(int j=0;j<w;j++){
    		if(a[i][j] & 1){
    			if(j != w-1) {
    				v.push_back({i, j, i, j+1});
    				a[i][j+1]++;
    			}else{
    				if(i != h-1) a[i+1][j]++, v.push_back({i, j, i+1, j});
    			}
    		}
    	}
    }
    cout << v.size() << endl;
    for(auto& i : v){
    	cout << i.a + 1 << " " << i.b + 1 << " " << i.c + 1 << " " << i.d + 1 << endl;
    }
    return 0;
}
