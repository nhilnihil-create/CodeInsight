#include <bits/stdc++.h>
#define rep(i, n) rep2(i, 0, n)
#define rep2(i, m, n) for (int i = m; i < (n); i++)
typedef long long ll;
using namespace std;

int main(){
    int n;
    cin >> n;
    
    int ans = 0;
    for(int i=1; i<=n; i+=2){
        int cnt =  0;
        rep2(j, 1, i+1){
            if(i%j==0)cnt++;
        }
        if(cnt==8)ans++;
    }
    
    cout << ans << endl;
}