#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
    ll n, m;
    cin >> n >> m;
    ll ans=1;
    ll i = 1;
    while(i<sqrt(m)){
        if(m%i==0){
            if(i>=n)ans = max(ans, m/i);
            else{
                if(i <= m/n){
                    ans = max(ans,i);
                }
            }
        }
        i++;
    }
    cout << ans << endl;
    return 0;
}