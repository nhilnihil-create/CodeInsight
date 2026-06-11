#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
/*
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
*/
#define ull unsigned long long int
#define ll long long int
#define MAX 1000000007
//1e9+7
#define pll pair<ll,ll>
#define pii pair<int,int>
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define FO ifstream fin("a.in");ofstream fout("a.out");
#define TEST ll T;cin>>T;while(T--)
#define all(x) (x).begin(),(x).end()
#define mset0(x) memset((x), 0, sizeof((x)));
#define mset1(x) memset((x), -1, sizeof((x)));
typedef tree<ll,null_type,less<ll>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;
int n,m,b;
ll a,c,ans=0,dif;
priority_queue<ll> pq;
map<ll,int> mp;
vector<ll> v,w;
vector<pll> u;
void solve(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a;
        v.push_back(a);
    }
    for(int i=0;i<m;i++){
        cin>>b>>c;
        u.push_back(pll(c,b));
    }
    sort(u.begin(),u.end());
    for(int i=m-1;i>=0;i--){
        c=u[i].first;b=u[i].second;
        while(b--) w.push_back(c);
        if(w.size()>=n) break;
    }
    for(auto x:v) w.push_back(x);
    sort(w.rbegin(),w.rend());
    for(int i=0;i<n;i++){
        ans+=w[i];
    }
    cout<<ans;

    return;
}
int main(){
    IO
    //TEST
    solve();
    return(0);
}
