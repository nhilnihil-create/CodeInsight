#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;

int main(){
    int n,m;
    cin >> n >> m;
    int mx = m/n;
    int ans = 1;
    for(int i=1;i*i<=m;i++){
        if(m%i == 0){
            if(i <=mx) ans = max(ans, i);
            if(m/i <= mx){
                ans = max(ans, m/i);
            }
        }
    }
    cout << ans << endl;
    return 0;
}