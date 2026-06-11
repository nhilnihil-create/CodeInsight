#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < (n); ++i)
#define ll long long
const ll mod = 1e9+7;
int inf = 1000000000; //10e9

int main(){

    int n, x;
    cin >> n >> x;
    
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    sort(a.begin(),a.end());

    int ans = 0, total = x;
    rep(i,n){
        if(a[i]<=total){
            ans++;
            total -= a[i];
        }else{
            break;
        }
    }
    if(ans == n && total != 0){
        ans = n-1;
    }


    cout << ans << endl;

    return 0;

}