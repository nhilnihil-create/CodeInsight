#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    ll N;
    cin >> N;
    ll ans =0;
    vector<ll> a(N),b(N);
    for(int i=0;i<N;i++){
        cin >> a[i];
    }
    for(int i=0;i<N;i++){
        cin >> b[i];
    }
    for(int i=0;i<N;i++){
        ll c = a[i]-b[i];
        if(c >0){
            ans += c;
        }else{
            ans += c/2;
        }
    }
    if(ans<=0){
        cout <<"Yes" <<endl;
    }else{
        cout <<"No"<<endl;
    }

    return 0;
}