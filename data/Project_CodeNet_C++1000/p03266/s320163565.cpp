#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define cans cout << ans << endl
#define cyes cout << "Yes" << endl
#define cno cout << "No" << endl
typedef long long ll;


int main(){
    int n,k;
    cin >> n >> k;
    ll ans = 0;
    if(k%2){
        ll now = n/k;
        ans = now*now*now;
    }
    else{
        ll now1 = n/k;
        ll now2 = 0;
        for(int i=1; i<=n; i++){
            if(i%k==k/2) now2++;
        }
        ans = now1*now1*now1 + now2*now2*now2;
    }
    cout << ans << endl;
    return 0;
}