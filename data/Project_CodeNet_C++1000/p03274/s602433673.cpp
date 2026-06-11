#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)

#define FOR(i,n,j) for(int i=(j);i<(n);++i)
#define ssort(n) sort((n).begin(),(n).end())
#define rsort(n) sort((n).begin(),(n).end(),greater<int>())
using ll=long long;
using ld=long double;
typedef pair<int,int> P;
typedef pair<P,int> COST;
#define repl(i,n) for(ll i=0;i<(n);++i)
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
using Graf=vector<vector<int>>;
#define MAX 10000000000000
#define L 10000
int main()
{
    int n,k;
    cin >> n >> k;
    vector<ll> x(n);
    vector<ll> dist(n-k+1,0);
    rep(i,n)cin >> x[i];
    rep(i,n-k+1){
        dist[i]=x[i+k-1]-x[i];
        
        dist[i]+=min(abs(x[i+k-1]),abs(x[i]));
        
    }
    
    ssort(dist);
    cout << dist[0] << endl;
}