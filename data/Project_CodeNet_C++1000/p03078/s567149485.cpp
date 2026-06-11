#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cstdlib>
#include<queue>

using namespace std;

#define rep(i, n) for(long int i = 0; i < n; i++)

int main(){
    long int x, y, z, k;
    cin >> x >> y >> z >> k;
    long int a[x], b[y], c[z];
    rep(i, x) cin >> a[i];
    rep(i, y) cin >> b[i];
    rep(i, z) cin >> c[i];
    long int a2[x*y];
    long int idx = 0;
    rep(i, x){
        rep(j, y){
            a2[idx] = a[i] + b[j];
            idx++;
        }
    }
    sort(a2, a2 + x * y, greater<long int>());
    long int num = min(k, x * y);
    long int a3[num*z];
    idx = 0;
    rep(i, num){
        rep(j, z){
            a3[idx] = a2[i] + c[j];
            idx++;
        }
    }
    sort(a3, a3 + num * z, greater<long int>());
    long int ans = 0;
    rep(i, k){
        cout << a3[i] << endl;
    }
}
