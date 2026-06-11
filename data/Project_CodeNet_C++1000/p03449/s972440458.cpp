#include<bits/stdc++.h>
using namespace std;
int sum1[105],sum2[105],arr1[105],arr2[105];
int main()
{
    int n,cnt,mx=0;
    cin>>n;
    for(int i= 1; i <= n; i++) {
        cin>>arr1[i];
        sum1[i] = sum1[i-1] + arr1[i];
    }
    for(int i = 1; i <= n; i++){
        cin>>arr2[i];
        sum2[i] = sum2[i-1] + arr2[i];
    }
    for(int i = 1; i <= n; i++) {
        cnt = sum1[i] + sum2[n] - sum2[i-1];
        mx = max(mx,cnt);
    }
    cout<<mx<<endl;
}
