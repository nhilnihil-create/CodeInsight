#pragma GCC target("avx2")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#include<bits/stdc++.h>
#define int ll
#define f			first
#define sz(a)       ((int)(a).size())
#define s			second
#define all(v)		v.begin(),v.end()
#define pii 		pair<int,int>
#define vpii 		vector<pii>
#define eb			emplace_back
#define pb			push_back
#define fo(i,n)		for(int i = 0;i<n;i++)
#define Fo(i,k,n)	for(int i=k;i<n;i++)
#define vi			vector<int>

using namespace std;
using ll  = long long;
using lld = long double;

const int oo = 0x3f3f3f3f;
const ll MOD = 1000000007;

const int N = 2e5 + 10;
int tree[N << 2] , a[N] , h[N];

void upd(int pos , int val , int l , int r , int t){
    if(l == r){
        tree[t] = val;
        return;
    }
    int mid = (l + r) >> 1;
    if(pos <= mid)
        upd(pos , val , l , mid , t << 1);
    else
        upd(pos , val , mid + 1 , r , t << 1 | 1);
    tree[t] = max(tree[t << 1] , tree[t << 1 | 1]);
}

int qry(int ql , int qr , int l , int r , int t){
    if(l > qr || r < ql)
        return 0;
    if(l >= ql && r <= qr)
        return tree[t];
    int mid = (l + r) >> 1;
    return max(qry(ql , qr , l , mid , t << 1) , qry(ql , qr , mid + 1 , r , t << 1 | 1));
}

signed main(){

#ifndef ONLINE_JUDGE
#endif
	ios_base::sync_with_stdio(0);cin.tie(0);
    
    int n;
    cin >> n;
    fo(i , n) cin >> h[i];
    fo(i , n) cin >> a[i];
    
    fo(i , n){
        int x = qry(0 , h[i] - 1 , 0 , N - 1 , 1);
        upd(h[i] , x + a[i] , 0 , N - 1 , 1);
    }

    cout << tree[1] << '\n';
    
    return 0;

}

