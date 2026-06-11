#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
const long long mod = 1e9 + 7;

int n;
int arr[MAXN];
int segtree[MAXN];
long long reqd;
long merge(long x, long y){
    return x + y;
}
void segtree_update(int ind, long val){
    for(segtree[ind += n] += val; ind > 1; ind >>= 1)
        segtree[ind >> 1] = merge(segtree[ind], segtree[ind ^ 1]);
}
long segtree_query(int l, int r){
    long res = 0;
    for(l += n, r += n; l < r; l >>= 1, r >>= 1){
        if((l & 1) == 1)
            res = merge(res, segtree[l++]);
        if((r & 1) == 1)
            res = merge(res, segtree[--r]);
    }
    return res;
}
bool check(int mid){
    map<int, int> mp;
    set<int> s;
    s.insert(0);
    int sum = 0;
    int i = 0;
    for(i = 0; i < n; i++){
        sum += (arr[i] <= mid) ? 1 : -1;
        s.insert(sum);
    }
    i = 0;
    for(int x : s)
        mp[x] = i++;
    memset(segtree, 0, sizeof(segtree));
    segtree_update(mp[0], 1);
    sum = 0;
    long long cnt = 0;
    for(i = 0; i < n; i++){
        sum += (arr[i] <= mid) ? 1 : -1;
        cnt += segtree_query(0, mp[sum]);
        segtree_update(mp[sum], 1);
    }
    return cnt >= reqd;
}
void solve(){
    int lo = 0, hi = 1e9, ans = -1;
    long long tot = n * 1LL * (n + 1) >> 1;
    if(tot % 2)
        reqd = (tot + 1) / 2;
    else
        reqd = (tot + 2) / 2;
    while(lo <= hi){
        int mid = (lo + hi) >> 1;
        if(!check(mid))
            lo = mid + 1;
        else{
            hi = mid - 1;
            ans = mid;
        }
    }
    cout << ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i = 0;
    cin >> n;
    for(i = 0; i < n; i++)
        cin >> arr[i];
    solve();
    return 0;
}
