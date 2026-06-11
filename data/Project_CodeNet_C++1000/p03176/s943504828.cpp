#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define pii pair<int,int>
#define int long long int
int n, h[200005] = {}, a[200005] = {}, dp[200005] = {}, tree[800005] = {};
void build(int l, int r, int now){
    if(l == r){
        tree[now] = 0;
        return;
    }
    int m = (l+r)/2;
    build(l, m, now * 2);
    build(l, m + 1, now * 2 + 1);
    return;
}
void update(int L, int R, int now, int k, int delta){
//    cout <<"test:" << L << ' ' << R << endl;
    if(L==R){
//        cout << "UPDATE:" << k << ' ' << L << ' ' << now << endl;
        tree[now] = delta;
        return;
    }
    int m = (L+R) / 2;
    if(m >= k){
        update(L, m, now * 2, k, delta);
    }else{
        update(m + 1 , R, now * 2 + 1, k ,delta);
    }
    tree[now] = max(tree[now * 2], tree[now * 2  + 1]);
    return;
}
int query(int L, int R, int l, int r, int now){
//    cout <<"test2:"<< L << ' ' << R << ' ' << l << ' ' << r << endl;
    if(L >= l && R <= r){
//        cout <<"query2:" << L << ' '<< R << ' ' << now << ' ' << tree[now] << endl;
        return tree[now];
    }
    int m = (L+R) / 2, a = 0, b = 0;
    if(l <= m){
        a = query(L, m, l, r, now * 2);
    }
    if(r > m){
        b = query(m + 1, R, l, r, now * 2 + 1);
    }
//    cout << "query:" << L << ' ' << m << ' ' << R << ' ' << a << ' ' << b << endl;
    return max(a, b);
}
int32_t main(){
    cin >> n;
    set<int> se;
    map<int, int> ma, ma2;
    for(int i = 0 ; i < n ; i++){
        cin >> h[i];
        se.insert(h[i]);
    }
    int cnt = 1;
    for(auto i : se){
//        ma.insert(pii(cnt, i));
        ma2.insert(pii(i, cnt));
        cnt++;
    }
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }
    int ans = 0;
    for(int i = 0 ; i < n ; i++){
        int qu = query(1, n, 1, ma2[h[i]], 1);
        dp[i] = qu + a[i];
//        cout << i << ' ' << qu << ' ' << ma2[h[i]] << ' ' << dp[i] << endl;
        ans = max(ans, dp[i]);
        update(1, n, 1, ma2[h[i]], dp[i]);
    }
    cout << ans << endl;
    return 0;
}
