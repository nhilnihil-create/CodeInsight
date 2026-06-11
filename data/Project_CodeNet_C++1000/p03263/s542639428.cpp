#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007, INF=mod*mod*3LL;
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

struct node{int y1, x1, y2, x2;};
int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int h, w;
    cin >> h >> w;
    vector<node> v;
    int a[h][w];
    for(int i=0;i<h;i++){
    	for(int j=0;j<w;j++){
    		cin >> a[i][j];
    	}
    }
    for(int i=0;i<h;i++){
    	for(int j=0;j<w;j++){
    		if(a[i][j] & 1){
    			if(j == w-1) {
    				if(i == h-1) continue;
    				else{
    					a[i+1][j]++;
    					v.push_back({i+1, j+1, i+2, j+1});
    				}
    			}else{
    				a[i][j+1]++;
    				v.push_back({i+1, j+1, i+1, j+2});
    			}
    		}
    	}
    }
    cout << v.size() << endl;
    for(auto& i: v){
    	cout << i.y1 <<" "<< i.x1 << " " << i.y2 <<" "<< i.x2 << endl;
    }
    return 0;
}
