#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define int long long
signed main(){
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int cnt=0;
    int xa=0;
    int xb=0;
    int r=0;

    for(int l = 0; l < n; l++) {
        while(r < n && (int)(xa^a[r])==xb+a[r]){
            //cout << l << " " << r << "\n";
            xa^=a[r];
            xb+=a[r];
            r++;
        }
        if(r==l) r++;
        else{
            xa^=a[l];
            xb-=a[l];
            cnt+=(r-l);
        }
    }
    cout << cnt << "\n";
    return 0;
}