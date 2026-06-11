#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int mod = 1e9+7;

int main(){
    int n,k;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
    }
    n -= k;
    int ans = 1;
    k--;
    if(n > 0){
        ans += n/k;
        if(n%k) ans++;
    }
    cout << ans << endl;
}