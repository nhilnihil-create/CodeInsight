#include <bits/stdc++.h>
using namespace std;
#define int long long int
// #include "../../Template.cpp"

class SegmentTree {
public:
    vector<int> tree;
    int n;
    SegmentTree(int size) {
        n = size;
        tree.assign(4*n+1, 0);
    }
    void update(int curr, int l, int r, int pos, int val) {
        if(l == r) {
            tree[curr] = max(tree[curr], val);
        }
        else {
            int mid = (l+r)/2;
            if(pos <= mid)
                update(curr*2, l, mid, pos, val);
            else
                update((curr*2)+1, mid+1, r, pos, val);
            tree[curr] = max(tree[curr*2], tree[(curr*2)+1]);
        }
    }
    int query(int curr, int l, int r, int i, int j) {
        if (j < l || i > r)
            return 0;
        if (i <= l && r <= j)
        {
            return tree[curr];
        }
        else {
            int mid = (l+r)/2;
            int left = query(curr*2, l, mid, i, j);
            int right = query((curr*2)+1, mid+1, r, i, j);
            return max(left, right);
        }
    }
};

int n;
vector<int> height;
vector<int> arr;

void solve() {
    int size = 1e6;
    SegmentTree tree(size);
    vector<int> dp(n+1, 0);
    for(int i = 0; i < n; i ++) {
        int best = tree.query(1, 1, size, 1, height[i]-1);
        dp[i] = best + arr[i];
        tree.update(1, 1, size, height[i], dp[i]);
    }
    int ans = 0;
    for(auto i : dp) {
        ans = max(ans, i);
    }
    cout << ans << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    height.assign(n+1, 0);
    arr.assign(n+1, 0);
    for(int i = 0; i < n; i ++) {
        cin >> height[i];
    }
    for(int i = 0; i < n; i ++) {
        cin >> arr[i];
    }
    solve();
    return 0;
}