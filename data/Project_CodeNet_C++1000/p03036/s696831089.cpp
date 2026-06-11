#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)

using namespace std;
int main(){
    int r, d, x;
    cin >> r >> d >> x;
    long long ans = x * r -d;
    rep(i , 10){
        cout << ans << endl;
        ans = ans * r -d;
    }
    return 0;
}
