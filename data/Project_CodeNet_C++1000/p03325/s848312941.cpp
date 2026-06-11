#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
#define int long long
using P = pair<int,int>;
signed main(){
    int n;cin >>n;
    int ans = 0;
    rep(i,n){
        int a;cin >> a;
        int cnt = 0;
        while(1){
            if(a%2 == 1)break;
            cnt++;
            a/=2;
        }
        ans += cnt;
    }
    cout <<ans << endl;
    
    return 0;
}