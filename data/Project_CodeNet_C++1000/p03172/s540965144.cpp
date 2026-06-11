#include<bits/stdc++.h>

using namespace std;
using ll=long long;

int t;
const int mod=1e9+7;

void add_self(int &a, int b){
    a+=b;
    if(a>=mod)a-=mod;
}

void sub_self(int &a, int b){
    a-=b;
    if(a<0)a+=mod;
}

void test_case(){
    int n,k;
    cin>>n>>k;
    vector<int>dp(k+1);
    dp[0]=1;
    for(int i=0; i<n; i++){
        int child;
        cin>>child;
        vector<int> cs(k+1);
        for(int candie=k-1; candie>=0; candie--){
            int l=candie+1, r=candie+child+1;
            // if(l>r)continue;
            add_self(cs[l],dp[candie]);
            if(r<=k)sub_self(cs[r],dp[candie]);
            // cout<<l<<" "<<r<<" "<<cs[l]<<" "<<cs[r]<<endl;
        }
        for(int i=0; i<=k; i++){
            if(i)add_self(cs[i],cs[i-1]);
            add_self(dp[i],cs[i]);
            // cout<<i<<" "<<cs[i]<<" "<<dp[i]<<endl;
        }
    }
    cout<<dp[k]<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    t=1;
    while(t--){
        test_case();
    }

    return 0;
}