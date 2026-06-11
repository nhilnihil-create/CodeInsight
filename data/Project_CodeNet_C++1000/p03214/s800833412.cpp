#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
typedef long long ll;

int main(){
    int n;
    cin >> n;
    double a[n];
    double ave = 0;
    rep(i,n) {
        cin >> a[i];
        ave += a[i];
    }
    ave /= (double)n;
    int ans = n;
    double d = 1e9;
    for(int i = n-1; i >= 0; i--){
        if(abs(ave-a[i]) <= d){
            ans = i;
            d = abs(ave-a[i]);
        }
    }
    cout << ans << endl;
    return 0;
}