#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define iter(it,a) for(auto it=a.begin();it!=a.end();it++)
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define preturn(X) cout<<X<<endl; return 0
typedef long long ll;
typedef long double ld;
const ll MOD = 1e9+7;
//cout.setf(ios::fixed); cout.precision(18)
 
const int N = 200000+10;
string s;
int n;
int val[N];
map<int,int> x;
int dp[N];
 
int main(){
    cin.tie(0);ios_base::sync_with_stdio(0);
    cin>>s;
    n = s.size();
    dp[0] = 0;
    x[0] = 0;
    val[0] = 0;
    rep(i,1,n+1){
        val[i] = val[i-1]^(1<<(s[i-1]-'a'));
        dp[i] = dp[i-1]+1;
        if(val[i]==0){
            dp[i] = 1;
        }
        rep(j,0,26){
            int temp = val[i]^(1<<j);
            if(temp==0){
                dp[i] = 1;
            }
            else if(x[temp]!=0){
                dp[i] = min(dp[i],dp[x[temp]]+1);
            }
        }
        x[val[i]] = i; 
    }
    preturn(dp[n]);
}