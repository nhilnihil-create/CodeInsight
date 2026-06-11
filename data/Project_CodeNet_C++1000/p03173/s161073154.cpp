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

int main()
{
    IOS;
    int n;
    cin>>n;
    ll a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    ll dp[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            dp[i][j]=LONG_MAX;
    }
    for(int i=0;i<n;i++)
        dp[i][i]=0;
    for(int k=2;k<=n;k++){
        for(int i=0;i<n-k+1;i++){
            ll s=a[i];
            for(int j=i+1;j<i+k;j++){
                s+=a[j];
                for(int l=i;l<j;l++)
                    dp[i][j]=min(dp[i][j],s+dp[i][l]+dp[l+1][j]);
            }
        }
    }
    cout<<dp[0][n-1];
}
