#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repi(i,a,b) for(int i=int(a);i<int(b);i++)
#define all(v) v.begin(), v.end()
#define ll long long
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<long long>;
using vvll = vector<vll>;

//snippets:tmp,cl,cvl,cs,co,coy,con,cov
//export PATH=:~/.local/bin

vvll comb(ll n) {
    vvll v(n + 1,vll(n + 1, 0));
    for (int i = 0; i < v.size(); i++) {
        v[i][0] = 1;
        v[i][i] = 1;
    }
    for (int j = 1; j < v.size(); j++) {
        for (int k = 1; k < j; k++) {
            v[j][k] = (v[j - 1][k - 1] + v[j - 1][k]);
        }
    }
    return v;
}

int main(){
    ll n;
    cin >> n;
    if(n%2==0){
        ll m=comb(n)[n][2]-n/2;
        cout << m << endl;
        repi(i,1,n+1){
            repi(j,i+1,n+1){
                if(i+j!=n+1){
                    cout << i <<" "<< j << endl;
                }
            }
        }
    }else{
        ll m=comb(n)[n][2]-n/2;
        cout << m << endl;
        repi(i,1,n){
            repi(j,i+1,n+1){
                if(i+j!=n){
                    cout << i <<" "<< j << endl;
                }
            }
        }
    }
}