#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool is_prime(long long N) {
    if (N == 1) return false;
    for (long long i = 2; i * i <= N; ++i) {
        if (N % i == 0) return false;
    }
    return true;
}

ll ans[100005];
ll q;

int main(){
    cin >> q;
    ans[0]=0;
    ans[1]=0;
    ans[2]=0;
    for(ll i=3;i<=100000;i++){
        if(is_prime(i)&&is_prime((i+1)/2)) ans[i]=ans[i-1]+1;
        else ans[i]=ans[i-1];
    }
    for(ll i=0;i<q;i++){
        ll l,r;
        cin >> l >> r;
        cout << ans[r]-ans[l-1] << endl;
    }
}
