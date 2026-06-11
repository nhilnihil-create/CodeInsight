#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define fo(i,CApiTaL_N) for(int i=0; i<CApiTaL_N; i++)
#define Fo(i,k,CApiTaL_N) for(int i=k; i<CApiTaL_N; i++)
#define ll long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define clr(x) memset(x, 0, sizeof(x))
#define tr(it, a) for(auto it=a.begin(); it!=a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

int t;
int n;
const int mod=1e9+7;
vl dp(1<<21+5);
vvi conn(21+1,vi(21+1));

void test_case(){
    cin>>n;
    dp[0]=1;
    fo(i,n)fo(j,n)cin>>conn[i][j];
    fo(mask,1<<n){
        int men=__builtin_popcount(mask);
        fo(bit,n){
            if(conn[men][bit]&&!(1<<bit&mask)){
                int target=(mask^(1<<bit));
                dp[target]=(dp[target]+dp[mask])%mod;
            }
        }
    }
    cout<<dp[(1<<n)-1]<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    t=1;
    while(t--){
        test_case();
    }
    
    return 0;
}