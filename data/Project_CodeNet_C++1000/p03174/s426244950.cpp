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

ll mod=1e9+7;

int main()
{
    IOS;
    int n;
    cin>>n;
    int a[n][n];
    map<int,vector<int>> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
            if(a[i][j]==1){
                m[i].push_back(j);
            }
        }
    }
    ll mask=1LL<<n;
    ll dp[mask];
    for(int j=0;j<mask;j++)
        dp[j]=0;
    dp[0]=1;
    for(int j=0;j<mask;j++){
        int i=__builtin_popcount(j);
        for(int x=0;x<m[i].size();x++){
            int k=m[i][x];
            if((j&(1<<k))==0){
                dp[j|(1<<k)]=(dp[j|(1<<k)]+dp[j])%mod;
            }
        }
    }
    cout<<dp[mask-1];
}
