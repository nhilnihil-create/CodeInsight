#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<long>a(n);
    vector<long>b(n);
    vector<long>c(n);
    for(int i=0;i<n;i++)cin >> a[i];
    for(int i=0;i<n;i++)cin >> b[i];
    for(int i=0;i<n;i++)cin >> c[i];
    
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    sort(c.begin(),c.end());

    vector<long>apl(n,0);
    vector<long>bpl(n,0);

    vector<long>bsum(n,0);

    for(int i=0;i<n;i++){
        auto it = upper_bound(c.begin(),c.end(),b[i]);
        bpl[i] = c.end() - it;
    }

    bsum[n-1] = bpl[n-1];
    for(int i=n-2;i>=0;i--){
        bsum[i] = bpl[i] + bsum[i+1];
    }

    for(int i=0;i<n;i++){
        auto it = upper_bound(b.begin(),b.end(),a[i]);
        apl[i] = bsum[it - b.begin()];
    }

    long ans = 0;
    for(int i=0;i<n;i++)ans += apl[i];

    cout << ans << endl;
    

    
}