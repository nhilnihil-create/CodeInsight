#include<bits/stdc++.h>
#define ll long long int
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
static const ll MAX = 1000000000000000;
static const int NIL = -1;
using namespace std;
const long double EPS = 0.0000000001;
const long double PI = (acos(-1));
const ll MOD = 1e9 + 7;

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")


ll floorl(ll num1, ll num2){
    if(num1%num2 == 0) return num1/num2;
    else return num1/num2+1;
}

int main(){
    ll n,x; cin >> n;
    ll sumA = 0, sumB = 0;
    ll countA = 0, countB = 0;
    vector<ll> a(n),b(n);

    rep(i,n) {
        cin >> a[i];
        sumA += a[i];
    }
    rep(i,n) {
        cin >> b[i];
        sumB += b[i];
    }

    if(sumB-sumA < 0) cout << "No";
    else {
        x = sumB-sumA;
        rep(i,n){
            if(a[i] > b[i]) {
                countB += a[i]-b[i];
            }else
            if(b[i] > a[i]){
                if((b[i]-a[i])%2 == 0) {
                    countA += (b[i]-a[i])/2;
                }else{
                    countB ++;
                    countA += (b[i]+1-a[i])/2;
                }
            }

        }

        if(max(countA,countB) <= x)  cout << "Yes";
        else cout << "No";
    }


}