#include "bits/stdc++.h"

using namespace std;

#define int long long int
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define se second
#define fi first

typedef pair<int, int> pii;
typedef vector<int> vi;

const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;

inline int add(int x, int y) { x += y; if (x >= mod) x -= mod; return x;}
inline int sub(int x, int y) { x -= y; if (x < 0) x += mod; return x;}
inline int mul(int x, int y) { return ((x % mod) * (y % mod)) % mod;}
inline int power(int a, int b) {
    int x = 1;
    while (b) {
        if (b & 1) x = mul(x, a);
        a = mul(a, a);
        b >>= 1;
    }
    return x;
}
inline int inv(int a) { return power(a, mod - 2);}

struct edge{
	int u,v,w;
};

vector<edge> edges;

#undef int
int main() {
#define int long long int
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int l; cin>>l;
    int r = (int)log2(l)+1;

    int x=1;
    for(int i=1;i<r;i++){
    	edges.pb({i,i+1,0});
    	edges.pb({i,i+1,x});
    	x=x*2;
    }
    int n=r;

    r=(int)log2(l-x)+1;
    while((l-x)){
    	edges.pb({r,n,x});
    	x=x+power(2,r-1);
    	r=(int)log2(l-x)+1;
    }

    int m=edges.size();
    cout<<n<<" "<<m<<endl;
    for(int i=0;i<m;i++){
    	cout<<edges[i].u<<" "<<edges[i].v<<" "<<edges[i].w<<endl;
    }
    
    return 0;
}


