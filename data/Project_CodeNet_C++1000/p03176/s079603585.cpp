#include <bits/stdc++.h>
using namespace std;

struct SegmentTree{
    int leaves;
    vector<long long int> data;

    void init(int n){
        leaves = 1;
        while(leaves < n) leaves *= 2;// nearest power of 2 (leaf nodes)
        data.assign(2 * leaves, 0);// (0,) 1, ..., 2 * leaves - 1
    }

    // update i-th leaf (0-indexed) to x
    void update(int i, long long int x){
        i += leaves;
        data[i] = x;
        while(i >= 2){
            i /= 2;// move upward (to the parent node)
            data[i] = max(data[i*2], data[i*2 + 1]);// compare the children
        }
    }

    // maximum [a,b)
    long long int query(int a, int b, int k, int l, int r){// k-th node of the tree = [l,r)
        if(b <= l || r <= a) return 0;// no overlap
        if(a <= l && r <= b) return data[k];// completely inside
        // otherwise: recursive
        long long int vl = query(a, b, k*2    , l      , (l+r)/2);// left  child
        long long int vr = query(a, b, k*2 + 1, (l+r)/2, r      );// right child
        return max(vl, vr);
    }
};

int main(){
    int n;
    cin >> n;

    vector<int> h(n);
    for(int i=0; i<n; i++){
        cin >> h[i];
    }
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    SegmentTree seg; 
    seg.init(n+1);

    for(int i=0; i<n; i++){
        seg.update(h[i], a[i] + seg.query(0, h[i], 1, 0, seg.leaves));
    }

    cout << seg.query(0, n+1, 1, 0, seg.leaves) << endl;
    return 0;
}