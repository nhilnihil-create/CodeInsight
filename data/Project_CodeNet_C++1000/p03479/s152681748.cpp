#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define rep(i,n); for(long long i = 0;i < (n);i++)
using ll = long long;
using P = pair<long long,long long>;
template <class T> using vec = vector<T>;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll x,y; cin >> x >> y;
    ll res = 0;
    while(y >= x){
        x *= 2;
        res++;
    }
    cout << res << endl;
}