#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
#define FOR(i,n,j) for(int i=(j);i<(n);++i)
#define rrep(i,n) for(int i=(n);i>=0;--i)
#define ssort(n) sort((n).begin(),(n).end())
using ll=long long;
using ld=long double;
typedef pair<int,int> P;
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define INF 10101010

int main()
{
    int N,M;
    cin >> N >> M;
    vector<int> x(M);
    rep(i,M)cin >> x[i];
    

    ssort(x);
    vector<int> dist(M-1);
    rep(i,M-1){
        dist[i]=x[i+1]-x[i];
    }
    sort(dist.begin(),dist.end());
    int ans=x[M-1]-x[0];
    if(N==1){
        cout << x[M-1]-x[0] << endl;
    }else if(N>=M){
        cout << 0 << endl;
    }
    else{
        rep(i,N-1){
            ans-=dist[M-2-i];
        }
        cout << ans << endl;
    }
}