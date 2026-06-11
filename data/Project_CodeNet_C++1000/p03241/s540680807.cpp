#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

//#define int long long
//signed main(){
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    int d=1;
    int ans=1;

    if(n==1){
        cout << m << "\n";
        return 0;
    }

    while(d<=m){
        if(m%d==0){
            if(m/d>=n) ans=d;
            else break;
        }
        if(m<n*d) break;
        d++;
    }
    cout << ans << "\n";

    return 0;
}