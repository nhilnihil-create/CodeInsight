#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>

int main(){
    ll N;
    cin >> N;
    ll ans=0;
    for(ll i=sqrt(N)+1; i>=1; i--){
        if(i*i<=N){ans=i*i;break;}
    }
    cout << ans << endl;
    return 0;
}