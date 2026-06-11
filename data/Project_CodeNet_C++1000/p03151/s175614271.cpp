#include <bits/stdc++.h>
using namespace std;
int main(){
    long n,ans = 0;
    cin >> n;
    long a[n],b[n],c[n],cnt=0;
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++){
        cin >> b[i];
        c[i] = a[i] - b[i];
    }
    for(int i=0;i<n;i++){
        if(c[i]<0){
            cnt += c[i];
            ans++;
        }
    }
    sort(c,c+n);
    for(int i=n-1;0<=i;i--){
        if(c[i]>0&&cnt<0){
            cnt += c[i];
            ans++;
        }
    }
    if(0<=cnt) cout << ans << endl;
    else cout << -1 << endl;
}