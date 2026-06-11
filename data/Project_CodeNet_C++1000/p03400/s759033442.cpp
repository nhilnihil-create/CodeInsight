
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()


int main(){
    int n, d, x;
    cin >> n >> d >> x;
    int ans = x;
    rep(i,n){
        int a;
        cin >> a;
        ans =ans + d/a + 1;
        if(d % a == 0) ans--;
    }
    cout << ans << endl;

}