#include <bits/stdc++.h>
#define pb push_back
#define rep(i,n) for(ll i = 0;i < (n); ++i)
typedef long long ll;
typedef long double la;
using namespace std;

int main(){
    string n;
    cin >> n;
    if(n.size() == 1){
        cout << n << endl;
        return 0;
    }
    ll ans = 0;
    ans += 9*(n.size()-1);
    string s;
    s += n[0];
    rep(i,n.size()-1) s+= '9';
    if(s != n){
        int num = n[0] - '1';
        cout << ans + num << endl;
        return 0;
    }
    if(s == n){
        int num = n[0] - '0';
        cout << ans+num << endl;
        return 0;
    } 
} 