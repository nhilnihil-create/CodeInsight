#include <bits/stdc++.h>
using namespace std;

#define IOS cin.sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define rep(i, n) for (int i = 0; i < n; i++)
#define repn(i, a, b) for (int i = a;i<=b;i++)
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define mem(x) memset(x, 0, sizeof(x))
#define ritr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
#define pai pair < int, int>
#define pal pair < ll, ll>
#define vi vector <int>
#define vl vector < ll >
#define vpai vector < pii >

const int mod = 1e9+7;
const int INF = INT_MAX;
const int sze = 200005;

ll tree[4*sze+1];
ll dp[sze];

int getMid(int s,int e){
    return (s+(e-s)/2);
}

void update(int ind,int ss,int se,int pos,ll val){

    if(ss==se){
        tree[ind]=val;
        dp[pos]=val;
        return;
    }
    int mid=getMid(ss,se);
    if(pos<=mid) update(2*ind,ss,mid,pos,val);
    else update(2*ind+1,mid+1,se,pos,val);

    tree[ind]=max(tree[2*ind],tree[2*ind+1]);
}

ll getMax(int ind,int ss,int se,int l,int r){
    if(l>se||r<ss) return 0;
    if(l<=ss&&se<=r) return tree[ind];

    int mid=getMid(ss,se);

    ll p1=getMax(2*ind,ss,mid,l,r);
    ll p2=getMax(2*ind+1,mid+1,se,l,r);

    return max(p1,p2);

}

void solve() {
    int n;
    cin>>n;
    int hei[n];
    ll be[n];
    rep(i,n) cin>>hei[i];
    rep(i,n) cin>>be[i];

    mem(tree);

    for(int i=0;i<n;i++){
        ll mx=getMax(1,1,n,1,hei[i]-1);
        update(1,1,n,hei[i],be[i]+mx);
    }
    //cout<<"hello\n";
    cout<<*max_element(dp,dp+sze)<<endl;


}

int main() {
    IOS;

    int t = 1;
    // cin >> t;
    while (t--) {
       solve();
    }

  return 0;
}
