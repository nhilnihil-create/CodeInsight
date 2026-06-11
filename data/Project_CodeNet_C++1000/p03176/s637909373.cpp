#include <bits/stdc++.h>
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp> 
// using namespace __gnu_pbds;   
#define ll long long
#define ull unsigned long long
// #define ordered_set tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag, tree_order_statistics_node_update> 
ll mod=1e9+7;
#define PI 3.1415926535897932385
#define inf 9e18
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
string char_to_str(char c){string tem(1,c);return tem;}
typedef pair<long long, long long> ii;
#define S second
#define F first
ll max(ll a,ll b){if(a>b){return a;}return b;}
ll min(ll a,ll b){if(a<b){return a;}return b;}
#define MAXN 200005
// Comment this out for interactice problem
// #define endl '\n'
// string to integer stoi() Remember: it takes string not character
// string to long long stoll()
// string.substr(position,length);
// integer to string to_string();
 
// To compile--> g++ -std=c++0x -o output one.cpp
// To run--> ./output
ll n;
ll tree[4*MAXN];
vector<ii> v;
ll a[MAXN];

void build(ll node, ll l, ll r){
    if(l>r){
        return;
    }
    if(l==r){
        tree[node]=a[l];
        return;
    }
    ll mid = (l+r)/2;
    build(2*node+1, l, mid);
    build(2*node+2, mid+1, r);
    tree[node] = max(tree[2*node+1], tree[2*node+2]);
}

void update(ll node, ll l, ll r, ll pos, ll val){
    if((l>r) || (l>pos) || (r<pos)){
        return;
    }
    if((l==r) && (l==pos)){
        tree[node]=val;
        a[l]=val;
        return;
    }
    ll mid = (l+r)/2;
    update(2*node+1, l, mid, pos, val);
    update(2*node+2, mid+1, r, pos, val);
    tree[node] = max(tree[2*node+1], tree[2*node+2]);
}

ll query(ll node, ll l, ll r, ll start, ll end){
    if((l>r) || (l>end) || (r<start)){
        return 0;
    }
    if((l>=start) && (r<=end)){
        return tree[node];
    }
    ll mid = (l+r)/2;
    ll z1 = query(2*node+1, l, mid, start, end);
    ll z2 = query(2*node+2, mid+1, r, start, end);
    return max(z1, z2);
}

int main()
{ 
    fastio;
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    cin>>n;
    for (int i = 0; i < n; ++i)
    {
        ll h;
        cin>>h;
        v.push_back({h, i});
    }
    for (int i = 0; i < n; ++i)
    {
        cin>>a[i];
    }
    sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); ++i)
    {
        ll ind = v[i].S;
        ll max1=0;
        if(ind==0){
            max1=a[0];
            update(0, 0, n-1, 0, a[i]);
        }
        else{
            max1=query(0, 0, n-1, 0, ind-1)+a[ind];
        }
        update(0, 0, n-1, ind, max1);
    }

    cout<<query(0, 0, n-1, 0, n-1);

    return 0;
}
