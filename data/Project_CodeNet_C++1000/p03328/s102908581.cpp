#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cmath>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
#define drep(i,cc,n) for(int i=cc;i>=n;--i)
typedef long long ll;
using namespace std;
int main(){
    ll a,b;
    cin>>a>>b;
    ll hoge=0;
    hoge = b - a;
    ll ans=0; 
    rep(i,1,hoge){
        ans += i;
    }
    ans = ans - b;
    cout<<ans<<endl;
    return 0;
}