#include <bits/stdc++.h>
using namespace std;
int main(){
    long long int n;
    cin >> n;
    long long int k;
    cin >> k;
    long long int a[n];
    long long int ans=0;
    long long int count;
    for(int i=0;i<n;i++)cin >> a[i];
    for(long long int i=40;i>=0;i--){
            count=0;
            for(int j=0;j<n;j++)if(a[j] & (1LL<<i))count++;
            if(count>=n-count || (1LL<<i)>k)ans+=(1LL<<i)*count;
            else{
                ans+=(1LL<<i)*(n-count);
                k-=(1LL<<i);
            }
    }
    cout << ans << endl;
}