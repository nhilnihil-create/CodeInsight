#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

int bs_upper_bound(int a[], int n, int x) {
    int l = 0;
    int h = n; // Not n - 1
    while (l < h) {
        int mid =  l + (h - l) / 2;
        if (x >= a[mid]) {
            l = mid + 1;
        } else {
            h = mid;
        }
    }
    return l;
}

int bs_lower_bound(int a[], int n, int x) {
    int l = 0;
    int h = n; // Not n - 1
    while (l < h) {
        int mid =  l + (h - l) / 2;
        if (x <= a[mid]) {
            h = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}

bool sortbysec(const pair<int,int> &a,const pair<int,int> &b) 
{ 
    return (a.second < b.second); 
} 

ll n,k;
vector<ll> a;
ll mod=1e9+7;

int main()
{
    IOS;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        ll x;
        cin>>x;
        a.push_back(x);
    }
    ll dp[k+2];
    for(int i=0;i<=k;i++)
        dp[i]=0;
    dp[0]=1;
    ll t[k+2];
    for(int i=0;i<n;i++){
        for(int j=0;j<=k+1;j++)
            t[j]=0;
        for(int j=k;j>=0;j--){
            int l=j+1;
            int r=min(j+a[i],k);
            if(l<=r){
                t[l]=(t[l]+dp[j])%mod;
                t[r+1]=(t[r+1]-dp[j]+mod)%mod;  
            }
        }
        ll p=0;
        for(int j=0;j<=k;j++){
            p=(p+t[j])%mod;
            dp[j]=(dp[j]+p)%mod;
        }
    }
    cout<<dp[k];
}
