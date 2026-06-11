#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,h;
    cin >> n >> h;
    int a[n],b[n];
    for(int i=0;i<n;i++)cin >> a[i] >> b[i];
    sort(a,a+n);
    sort(b,b+n);
    int ans=0;
    for(int i=n-1;i>=0;i--){
        h -= b[i];
        ans++;
        if(h<=0)break;
        if(a[n-1]>b[i-1])break;
    }
    if(h<=0){
        cout << ans;
        return 0;
    }
    cout << ans + (h+a[n-1]-1)/a[n-1];
}