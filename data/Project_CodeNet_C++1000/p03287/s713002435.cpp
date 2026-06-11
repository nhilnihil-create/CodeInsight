#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define int long long
signed main(){
//int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    vector<int> a(n+1);
    a[0]=0;
    for(int i = 0; i < n; i++) {
        int ta;
        cin >> ta;
        a[i+1]=a[i]+ta;
    }
    for(int i = 0; i < n+1; i++) {
        a[i]%=m;
    }
    sort(a.begin(),a.end());
    int cnt=1;
    int ans=0;
    for(int i = 0; i < n; i++) {
        if(a[i+1]==a[i]) cnt++;
        else{
            ans+=cnt*(cnt-1)/2;
            cnt=1;
        }
    }
    if(a[n]==a[n-1]) ans+=cnt*(cnt-1)/2;
    cout << ans << "\n";
    return 0;
}