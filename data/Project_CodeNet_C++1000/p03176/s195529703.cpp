#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi 2*acos(0.0)
#define f first
#define s second
#define pb push_back
#define gap ' '
#define fastio {ios_base::sync_with_stdio(false);cin.tie(NULL);}
#define mod 1000000007
#define N 200005
int n;
ll h[N],ara[N];
ll tree[N * 4];

ll query(int node, int b, int e, int i, int j)
{
    if (i > e || j < b)
        return 0;
    if (b >= i && e <= j)
        return tree[node];
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    ll p1 = query(Left, b, mid, i, j);
    ll p2 = query(Right, mid + 1, e, i, j);
    return max(p1 , p2);
}
void update(int node, int b, int e, int i, ll newvalue)
{
    if (i > e || i < b)
        return;
    if (b >= i && e <= i) {
        tree[node] = newvalue;
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    update(Left, b, mid, i, newvalue);
    update(Right, mid + 1, e, i, newvalue);
    tree[node] = max(tree[Left] , tree[Right]);
}
int main()
{
    fastio;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>h[i];
    for(int i=1;i<=n;i++) cin>>ara[i];
    for(int i=n;i>=1;i--)
    {
        ll mx=query(1,1,n,h[i],n);
        update(1,1,n,h[i],ara[i]+mx);
    }
    cout<< query(1,1,n,1,n) <<endl;

}
