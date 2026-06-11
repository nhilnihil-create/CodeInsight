#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<#x<<" = "<<x<<endl;
typedef long long int ll;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    int arr[n];
    int arr2[n];
    int arr3[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        cin>>arr2[i];
        cin>>arr3[i];

    }
    int ans[n];
    int ans2[n];
    int ans3[n];
    ans[0]=arr[0];
    ans2[0]=arr2[0];
    ans3[0]=arr3[0];
    for(int i=1;i<n;i++){
        ans[i]=arr[i]+max(ans2[i-1],ans3[i-1]);
        ans2[i]=arr2[i]+max(ans3[i-1],ans[i-1]);
        ans3[i]=arr3[i]+max(ans2[i-1],ans[i-1]);
    }
    int res=max({ans[n-1],ans2[n-1],ans3[n-1]});
    cout<<res<<"\n";
}
