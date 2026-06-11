#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define N 550
#define INF 1000000000
typedef long long ll;
#define ALL(v) (v).begin(),(v).end()
#define SZ(x) int(x.size())
#define IN(a) cin>>(a)
#define OUT(a) cout<<(a)<<endl
typedef pair<int,int> P;
const int MAX = 1000000;
const int MOD = 1000000007;
int main(){
    int n,m;
    cin>>n>>m;
    vector<int>a(n);
    REP(i,n)cin>>a[i];
    vector<ll>s(n+1);
    s[0]=0;
    REP(i,n){
        s[i+1]=s[i]+a[i];
    }
    map<int,int>w;
    REP(i,n){
        w[s[i+1]%m]++;
    }
    w[0]++;
    ll ans=0;
    for(auto p:w){
        ans+=(ll)p.second*(p.second-1)/2;
    }
    OUT(ans);
    return 0;
}