#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin >> n>>k;
    int p[n];
    for(int i=0;i<n;i++)cin >> p[i];
    sort(p,p+n);
    int ans=1e9;
    for(int i=0;i<n-k+1;i++){
        ans=min(ans,p[i+k-1]-p[i]);
    }
    cout << ans << endl;
}