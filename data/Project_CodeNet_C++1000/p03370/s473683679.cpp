#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,x;
    cin >> n >> x;
    int m[n];
    int ans=n;
    for(int i=0;i<n;i++)cin >> m[i];
    for(int i=0;i<n;i++)x-=m[i];
    sort(m,m+n);
    ans += x/m[0];
    cout << ans << endl;
}