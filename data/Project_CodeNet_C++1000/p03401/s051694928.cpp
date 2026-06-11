#include<iostream>
#include<string>
#include<algorithm>
#include<queue>
#include<vector>
#include<cstdlib>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    int n;
    cin >> n;
    int a[n+2];
    rep(i, n) cin >> a[i+1];
    a[0] = 0;
    a[n+1] = 0;
    int sm = 0;
    rep(i, n + 1) sm += abs(a[i+1] - a[i]);
    rep(i, n){
        int ans = sm;
        ans -= abs(a[i] - a[i+1]);
        ans -= abs(a[i+1] - a[i+2]);
        ans += abs(a[i] - a[i+2]);
        cout << ans << endl;
    }
    
}