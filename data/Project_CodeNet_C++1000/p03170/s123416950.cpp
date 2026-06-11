#include<bits/stdc++.h>
using namespace std;

vector<int> arr;
vector<int> dp;
int mn;

int main() {
    int n,k;
    cin>>n>>k;
    arr.resize(n);
    dp.resize(k+1,0);
    for(int i=0;i<n;i++) cin>>arr[i];
    mn= *min_element(arr.begin(),arr.end());

    for(int i=0;i<mn;i++) dp[i]=0;

    for(int i=0;i<=k;i++) {
        for(int j: arr) {
            if(i+j<=k) {
                dp[i+j]= max(dp[i]^1,dp[i+j]);
            }
        }
    }

    if(dp[k]) cout<<"First";
    else cout<<"Second";
}