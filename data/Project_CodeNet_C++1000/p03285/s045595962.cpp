#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
#define rep2(i,a,b) for (ll i = (a); i < (b); ++i)
#define INF (1<<18)




int main() {
    int n;
    cin>>n;

    bool ans = false;
    rep(i,30)rep(j,20){
        if(4*i+j*7 ==n) ans=true;
    }

    cout<< (ans ? "Yes" : "No") <<endl;
    return 0;
}