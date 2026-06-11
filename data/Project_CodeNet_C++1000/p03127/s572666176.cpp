#include <iostream>
#include <vector>
using namespace std;
int gcd(int a, int b){
    if( a < b ) swap(a,b);
    if(a%b == 0) return b;
    else return gcd(b,a%b);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    int ans = a[0];
    for(int i = 1; i < n; ++i){
        ans = gcd(ans, a[i]);
    }
    cout << ans << endl;
    return 0;
}