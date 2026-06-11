#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, h, ans=0, am=0;
    cin >> n >> h;
    vector<int> a(n), b(n);

    for(int i=0; i<n; i++) {
        int x, y;
        cin >> x >> y;
        a[i]=x;
        am=max(a[i], am);
        b[i]=y;
    }
    sort(b.begin(), b.end());
    reverse(b.begin(), b.end());
    for(int i=0; i<n; i++) {
        if(b[i]>am) {
            ans++;
            h-=b[i];
            if(h<=0) break;
        }
    }
    if(h>0){
        ans+=(h+am-1)/am;
    }
    cout << ans;
}