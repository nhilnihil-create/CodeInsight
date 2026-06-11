#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

ll minx;
int n;
vector<ll> a;

int main()
{
    IOS;
    int k;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        ll x;
        cin>>x;
        a.push_back(x);
    }
    bool dp[k+1];
    minx=a[0];
    for(int i=0;i<n;i++){
        minx=min(a[i],minx);
    }
    for(int i=0;i<=k;i++){
        dp[i]=false;
    }
    for(int i=0;i<n;i++){
        dp[a[i]]=true;
    }
    for(int i=0;i<minx;i++){
        dp[i]=false;
    }
    for(int i=0;i<=k;i++){
        for(int j=0;j<n;j++){
            if(i-a[j]>=0 && dp[i-a[j]]==false){
                dp[i]=true;
            }
        }
    }
    if(dp[k]==false)
        cout<<"Second";
    else
        cout<<"First";
}
