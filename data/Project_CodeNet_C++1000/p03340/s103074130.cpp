#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1001001001;

int main(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    ll ans = 0;
    int tmp = 0;
    int r = 1;
    for(int l = 0; l < n ; l++){
        if(tmp == 0) tmp = a[l];
        if(l == r) r++;
        while(r < n){
            if((tmp & a[r]) == 0){
                tmp ^= a[r];
                r++;
            }
            else{
                ans += r - l;
                tmp ^= a[l];
                break;
            }
        }
        if(r == n){
            ans += r - l;
        }
    }
    cout << ans << endl;
}