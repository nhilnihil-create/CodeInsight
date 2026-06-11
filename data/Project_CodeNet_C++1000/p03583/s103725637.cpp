#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define per(i,n) for(int i=(n)-1; i>=0; i--)
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
using namespace std;
using ll = long long;
using vi = vector<int>;
using vv = vector<vi>;
const int MOD = 1000000007;

int main(){
    ll n; cin >> n;
    
    for(ll h=1; h<=3500; h++){
        for(ll w=1; w<=3500; w++){
            ll num = n*h*w;
            ll den = 4*h*w - n*w - n*h;
            if(den>0 && num%den==0){
                cout << h <<" "<< w <<" "<< num/den << endl;
                return 0;
            }
        }
    }
    
    return 0;
}