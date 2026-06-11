#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct SegmentTree {
private:
    int n;
    vector<int> node;
 
public:
    SegmentTree(vector<int> v) {
        int sz = v.size();
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1, 0);
        for(int i=0; i<sz; i++) node[i+n-1] = v[i];
        for(int i=n-2; i>=0; i--) node[i] = (node[2*i+1] + node[2*i+2]);
    }
 
    void add(int x, int val) {
        x += (n - 1);
        node[x] += val;
        while(x > 0) {
            x = (x - 1) / 2;
            node[x] = (node[2*x+1] + node[2*x+2]);
        }
    }
    // hannkaikukann 
    int getsum(int a, int b, int k=0, int l=0, int r=-1) {
        if(r < 0) r = n;
        if(r <= a || b <= l) return 0;
        if(a <= l && r <= b) return node[k];
 
        int vl = getsum(a, b, 2*k+1, l, (l+r)/2);
        int vr = getsum(a, b, 2*k+2, (l+r)/2, r);
        return (vl + vr);
    }
};


#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;

int main() {
    //cout.precision(10);
    ll n;
    cin >> n;
    int a[100050];
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    if(n == 1){
        cout << a[1] << endl;
        return 0;
    }
    ll ok = 1;
    ll ng = 1000000005;
    while(ng - ok > 1){
        ll mid = (ok + ng) / 2;
        int b[200050];
        for(int i = 1; i <= n; i++){
            if(a[i] >= mid){
                b[i] = 1;
            } else {
                b[i] = -1;
            }
        }
        int sum = 100000;
        vector<int> v(200050);
        SegmentTree seg(v);
        ll inversion = 0;
        bool checker = false;
        seg.add(100000, 1);
        for(int i = 1; i <= n; i++){
            sum += b[i];
            inversion += seg.getsum(0, sum + 1);
            //cout << mid << " " << i << " " << seg.getsum(0, sum + 1) << " " << inversion << endl;
            seg.add(sum, 1);
            if(inversion >= (n * (n + 1) / 4)){
                checker = true;
                break;
            }
        }
        if(checker){
            ok = mid;
        } else {
            ng = mid;
        }
    }
    cout << ok << endl;
    return 0;
}
