#include<bits/stdc++.h>
using namespace std;
int main(){
    long long int n;
    cin >> n;
    long long int a[n];
    long long int sum=0;
    for(long long int i=0;i<n;i++){
        cin >> a[i];
        a[i] -= (i+1);
        sum += a[i];
    }
    sort(a,a+n);
    long long int tmp=0;
    long long int ans=1e18;
    for(long long int i=0;i<n;i++){
        tmp += a[i];
        ans=min(ans,sum+(2*(i+1)-n)*a[i]-2*tmp);
    }
    cout << ans << endl;
}