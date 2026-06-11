#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define deb(x) cout<< #x << " " << x << "\n";
#define MAX 9223372036854775807
#define MIN -9223372036854775807
#define PI 3.141592653589
#define setbits(n) __builtin_popcountll(n)
const ll mod=1e9+7;

const int N=1e5+1;
bool dp[N][2],vis[N][2];
vector<int> a(N);
ll n,k;

bool go(int left, int mov){
    if(left<0) return true;
    if(vis[left][mov]==true)
        return dp[left][mov];
    //cerr<<left<<"\n";
    bool win=false;
    for(int i=0;i<n;i++)
        win|=(!go(left-a[i],mov^1));
    vis[left][mov]=true;
    return dp[left][mov]=win;
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll T=clock();
    
    cin>>n>>k;
    memset(vis,false,sizeof(vis));
    for(ll i=0;i<n;i++)
        cin>>a[i];
    if(go(k,0))
        cout<<"First";
    else
        cout<<"Second";

    

    cerr<<"\n\nTIME: "<<(double)(clock()-T)/CLOCKS_PER_SEC<<" sec\n";
    T = clock();
    return 0;
}