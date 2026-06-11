#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

signed main(){
    ios::sync_with_stdio(false);
	cin.tie(0);


    int n;
    cin>>n;
    int c[n];
    vector<vector<int>> v(200005);
    for(int i=0;i<n;i++){
        cin>>c[i];
        v[c[i]].push_back(i);
    }
    ll mod=1e9+7;
    ll ans=0;
    vector<pair<int,int>> p;
    for(int i=0;i<200005;i++){
        if(v[i].size()>1){
            int a=v[i][0];
            for(int j=1;j<v[i].size();j++){
                int b=v[i][j];
                if(a+1!=b) p.push_back(make_pair(b,a));
                a=b;
            }
        }
    }
    sort(p.begin(),p.end());
    ll dp[n+1]={};
    dp[0]=1;
    int r=0;
    for(int i=0;i<n;i++){
        dp[i+1]+=dp[i];
        dp[i+1]%=mod;
        if(r<p.size() && i==p[r].first){
            dp[i+1]+=dp[p[r].second+1];
            dp[i+1]%=mod;
            r++;
        }
    }
    cout<<dp[n]<<endl;    
    
}