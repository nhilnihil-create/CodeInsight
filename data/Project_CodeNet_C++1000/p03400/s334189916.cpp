#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < (n); ++i)
#define ll long long
const ll mod = 1e9+7;
int inf = 1000000000; //10e9

int main(){

    int n, d, x;
    cin >> n >> d >> x;
    
    vector<int> a(n);
    rep(i,n) cin >> a[i];

    int ans = 0, consume = 0;
    rep(i,n){
        consume += 1 + (d-1)/a[i];
    }
    ans = consume + x;


    cout << ans << endl;

    return 0;

}