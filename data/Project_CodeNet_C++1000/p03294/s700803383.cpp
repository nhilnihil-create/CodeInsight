
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;

//m=a1*a2*・・・とするとm-1はどのaでmodをとってもa-1になる
//それが分かっているのでfの最大値は全てのaを足してnを引けば良い
int main(){
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];

    ll sum=0;
    rep(i,n){
        sum += a.at(i);
    }
    cout << sum - n << endl;
}