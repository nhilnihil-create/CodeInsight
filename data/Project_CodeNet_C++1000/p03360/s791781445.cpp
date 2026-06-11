#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll A,B,C,K;
    cin>>A>>B>>C>>K;
    ll ma=max(max(A,B),C);
    ll ans=A+B+C-ma;
    rep(i,0,K){
        ma*=2;
    }
    ans+=ma;
    cout << ans << endl;
    return 0;
}