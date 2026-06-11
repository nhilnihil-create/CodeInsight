#include <bits/stdc++.h>
using namespace std;

#define M 1000000007
#define ll long long int
#define endl "\n"
#define pb push_back
vector<bool> dp(100005);

void stone(int n, vector<ll> v, int k){
    for(int i=1; i<=k; i++){
        bool flag = 0;
        for(int j=0; j<n; j++){
            if(i-v[j]<0) { dp[i]=0; break; }
            else if(!dp[i-v[j]]) { dp[i]=1; flag=1; break; }
        }
        if(flag==0) dp[i]=0;
    }
    if(dp[k]==1) cout<<"First"<<endl;
    else cout<<"Second"<<endl;
}

int main(){
    ll n,k;
    cin>>n>>k;
    vector<ll> v(n);
    for(int i=0; i<n; i++) cin>>v[i];
    sort(v.begin(), v.end());
    stone(n,v, k);
    return 0;
}
