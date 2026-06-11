#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define rep(i,n); for(long long i = 0;i < (n);i++)
using ll = long long;
using P = pair<long long,long long>;
template <class T> using vec = vector<T>;
#ifdef local
#include "debug.cpp"
#else
#define debug(...)
#endif

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(10);
    ll n; cin >> n;
    vec<ll> a(n);
    ll sum=0,k=0;;
    rep(i,n){
        cin >> a[i];
        if(a[i]<0){
            a[i]*=-1;
            k++;
        }
        sum+=a[i];
    }
    sort(a.begin(),a.end());
    cout << (k%2==0 ? sum : sum - 2*a[0]) << endl;
}