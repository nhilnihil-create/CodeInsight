#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
long long mo = 1e9 + 7;
typedef long long ll;
typedef pair<int,int> P;

int main(){
    long double N;
    cin >> N;
    long ans=-1;
    ll ii,jj;
    for(ll i=1; i<=3500; i++){
        ii = i;
        for(ll j=1; j<=3500; j++){
            jj = j;
            ll Z = N*i*j;
            ll W = 4*i*j - N*i - N*j;
            if(W > 0 && Z % W == 0){
                ans = Z / W;
                break;
            }
        }
        if(ans != -1)break;
    }
    cout << ii <<" "<< jj <<" "<< ans << endl;
}