#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define NUM 1000000007
#define MAX 100001
#define INF LLONG_MAX
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,tmp;
    cin>>n;
    vector<ll> v;
    ll sum = 0;
    for(int i=0;i<n;i++){
        cin>>tmp;
        v.pb(tmp);
        sum+=tmp;
    }
    bitset<4040040> dp;
    dp[0]=1;
    for(int i=0;i<n;i++){
        dp|=dp<<v[i];
    }
    ll ans = (sum+1)/2;
    for(ll i=ans;i<=sum;i++){
        if(dp[i]){
            cout<<i<<endl;
            break;
        }
    }
    return 0;
}
