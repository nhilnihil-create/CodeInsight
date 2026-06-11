#include <bits/stdc++.h> 
using namespace std; 
typedef long long ll;
const ll mxN=1e9;
const ll mod = 1e9+7;

ll pow(ll a,ll b){

    ll r =1;

    while(b){
        if(b%2!=0) r=(r*a);
        a=(a*a);
        b/=2;
    }

    return r;
}

const int sz = 5e5+20;
ll fact[sz], inv[sz];
void pre(){
	fact[0] = 1;
	inv[0] = pow(fact[0], mod-2);
	for(int i=1;i<sz;i++){
		fact[i] = (fact[i-1]*i)%mod;
	}
}

int allmask;
int dp[1<<21];
int n;
vector<vector<int>> v(22);

int count(int a,int j){
    
    if(a==allmask) return 1;
    if(j>=n) return 0;

    if(dp[a]!=-1) return dp[a];
    
    int ways = 0;
    for(int i=0;i<v[j].size();i++){
        if(!(a&(1<<v[j][i]))) ways+=(count(a|(1<<v[j][i]),j+1));
        ways%=mod;
    }

    return dp[a]=ways;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int a;
            cin>>a;
            if(a) v[i].push_back(j);
        }
    }

    memset(dp,-1,sizeof(dp));
    allmask = (1<<n)-1;

    cout<<count(0,0);
}