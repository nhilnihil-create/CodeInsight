#include <bits/stdc++.h>

#define IO  ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
#define endl '\n'
using namespace std;
int main()
{
    IO
    int n,k,mn=1e9;
    cin>>n>>k;
    k--;
    int arr[n+5];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    for(int i=0;i<n;i++){
        if(i+k>=n) break;
        mn=min(mn,arr[i+k]-arr[i]);
    }
    cout<<mn;
    return 0;
}