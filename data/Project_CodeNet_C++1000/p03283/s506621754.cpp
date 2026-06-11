#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define _GLIBCXX_DEBUG

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vd = vector<double>;
using vvi = vector<vi>;
using vvll = vector<vll>;
using vvd = vector<vd>;
using vvvi = vector<vvi>;
using vvvll = vector<vvll>;
using vvvd = vector<vvd>;

const double pi=acos(-1);
const ll MOD=1e9+7;
const ll INF=(1LL<<60);

ll dp[510][510];
int flag[510][510];
int d[510][510];
int n,m,q;

ll ddpp(int l,int r){
    if (flag[l][r])return dp[l][r];
    flag[l][r]=1;
    if (l==r){
        dp[l][r]=d[l][l];
        return d[l][l];
    }
    else if (r==l+1){
        dp[l][r]=d[l][r]+ddpp(l+1,r)+ddpp(l,r-1);
        return dp[l][r];
    }
    else{
        dp[l][r]=d[l][r]+ddpp(l+1,r)+ddpp(l,r-1)-ddpp(l+1,r-1);
        return dp[l][r];
    }
}

int main() {
    cin>>n>>m>>q;
    memset(d,0,sizeof(d));
    rep(i,m){
        int l,r;
        cin>>l>>r;
        d[l][r]+=1;
    }
    ddpp(1,n);
    rep(i,q){
        int p1,q1;
        cin>>p1>>q1;
        cout<<dp[p1][q1]<<endl;
    }
    
    

    return 0;
}