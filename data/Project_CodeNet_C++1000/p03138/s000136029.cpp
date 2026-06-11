#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cstdlib>
#include<queue>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    long int n, k;
    cin >> n >> k;
    long int a[n];
    rep(i, n) cin >> a[i];
    long int bit[42];
    rep(i, 42) bit[i] = 0;
    rep(i, n){
        rep(j, 42){
            if (((a[i] >> j) & 1) == 1){
                bit[j]++;
            }
        }
    }
    long int num = 0;
    for (long int i = 41; i >= 0; i--){
        if (bit[i] <= n / 2){
            if (num + ((long int)1 << i) <= k){
                num += ((long int)1 << i);
            }
        }
    }
    long int ans = 0;
    rep(i, n){
        ans += num ^ a[i];
    }

    cout << ans << endl;
}
