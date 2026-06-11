
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int N,K;
    cin>>N>>K;
    ll cnt;
    ll ans;
    cnt = N/K;

    ans = cnt*cnt*cnt;

    if(K % 2 == 0) {
        ll add = 0;
        for(int i=1; i<=N; i++){
            if(i % K == K/2 && (K % 2 == 0)){
                add++;
            }
        }
        ans += add*add*add;
    }

    cout<<ans<<endl;

    return 0;        
}