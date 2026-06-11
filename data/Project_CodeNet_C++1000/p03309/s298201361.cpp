#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define rep(i, n)   for(int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main(){
    int n;  cin >> n;
    vector<ll>a(n);
    rep(i, n){
        int tmp;    cin >> tmp;
        a[i] = tmp-(i+1);
    }
    sort(a.begin(), a.end());
    ll ans = 1000000000000000;
    rep(i, 2){
        ll b = a[n/2 + i];
        ll tmp = 0;
        rep(j, n){
            tmp += abs(a[j] - b);
        }
        ans = min(ans, tmp);
    }
    cout << ans << endl;
}
