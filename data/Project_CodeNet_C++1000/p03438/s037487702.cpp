#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll N;
    cin >> N;
    ll big =0;
    ll small=0;
    vector<ll> a(N);
    for(int i=0;i<N;i++){
        cin >> a[i];
    }
    vector<ll> b(N);
    for(int i=0;i<N;i++){
        cin >> b[i];
    }
    for(int i=0;i<N;i++){
        ll temp = a[i] -b[i];
        if(temp<0){
            small -= temp/2;
        }else{
            big += (temp);
        }
    }
    if(big-small<=0){
        cout <<"Yes" << endl;
    }else{
        cout <<"No" << endl;
    }

    return 0;
}