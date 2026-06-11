#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <algorithm>
#define rep(i,n) for (int i = 0;i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int INF = 1e9;

int D = 50;
ll calc(ll n){
    int j = 0;
    ll m = 1;
    m <<= D;
    ll ret = 0;
    for(int i = D;i>=2;i--){
        //cout << m << endl;
        if(m<=n*2){
            //cout << m << endl;
            ret = ret*2 + max(n%m - m/2 + 1,ll(0))%2;
            j++;
        }
        m >>= 1;
    }
    ret = ret*2 + ((n+1)/2)%2;
    return ret;
}

int main(){
    ll a,b;cin >> a >> b;
    ll c = calc(a-1);
    ll d = calc(b);
    cout <<(c^d)<<endl;

    
    //cout << calc(a) << " " << calc(b) << endl;
    // ll c = calc(a)^calc(b);
    // cout <<  c<< endl;

}