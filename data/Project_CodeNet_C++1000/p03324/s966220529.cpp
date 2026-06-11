#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,x) for(int i=0;i<x;i++)
#define put(ans)    cout << ans << endl;

int main(){
    int a,b;
    cin >> a >> b;

    if(a>0){
        ll ans(0);
        int t(1);
        rep(i,a)    t *= 100;
        rep(i,b){
            ans += t;
        }
        if(b==100)  ans += t;

        cout << ans << endl;
    }else{
        int ans(0);
        if(b==100){
            cout << 101 << endl;
        }else
            cout << b << endl;
    }

    return 0;
}