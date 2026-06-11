#include <bits/stdc++.h>
using namespace std;

//最大公約数を求める関数 O(logb)
int64_t gcd(int64_t a, int64_t b){
    return b ? gcd(b, a % b) : a;
}

int main(){
    int n;
    cin >> n;
    int a[111000];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    int ans = a[0];
    for(int i=1; i<n; i++){
        ans = gcd(ans, a[i]);
    }
    cout << ans << endl;
    return 0;
}