/* To Kaise Hain Aaplog*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define all(x) (x).begin(), (x).end()

void shuru_krte_hai_bina_kisi_bakchodi_ke()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
}
const ll m = 998244353;

const ll s = 1e6 + 2;
vector<ll> v[s];
bool vis[s]={0};

void dfs(int s){
    vis[s] = true;
    for(int node : v[s]){
        if(!vis[node]){
            dfs(node);
        }
    }
}
int main()
{
    //shuru_krte_hai_bina_kisi_bakchodi_ke();

/* long long yaad se daal de har jagah*/
#define int long long

    int n,m,ans=0;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i);
            ans++;
        }
    }
    cout<<ans;
    return 0;
}