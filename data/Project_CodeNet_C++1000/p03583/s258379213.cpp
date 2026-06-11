#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

const int INF=1e9;
const int MOD=1e9+7;

int main(){
    ll N; cin >> N;
    for(ll i=1;i<=3500;i++){
        for(ll j=1;j<=50000;j++){
            ll x=N*i*j;
            ll y=(4*i*j-(i+j)*N);
            if(y<=0) continue;
            if(x%y==0){
                cout << i << " " << j << " " << x/y << endl;
                return 0;
            }
        }
    }
}
