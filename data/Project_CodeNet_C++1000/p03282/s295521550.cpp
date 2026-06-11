#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep2(i,n) for(int i=1;i<(n);i++)
typedef long long ll;


int main() {
    string s; cin >> s;
    ll k; cin >> k;
    ll ans=1;
    ll n=s.size();
    n= min(n,k);
    rep(i,n){
        if(s.at(i)!='1'){
            cout << s.at(i) << endl;
            return 0;
        }
    }
    cout << '1' << endl;
    return 0;
}