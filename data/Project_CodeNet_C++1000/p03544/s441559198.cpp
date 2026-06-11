#include<bits/stdc++.h>
 using namespace std;
 const long long MOD = 1e9+7;
 #define rep(i,n) for(int i=0;i<n;++i)
 typedef long long int ll;
 typedef unsigned long long ull;
 template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
 template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
 typedef pair<ll,ll> P;
int main(){

    long n;
    cin >> n;

    vector<ll> a(n+1);

    a[0] = 2;
    a[1] = 1;

    for(int i = 2; i < n+1; i++){
        a[i] = a[i-1] + a[i-2];
    }

    cout << a[n] << endl;

}
