#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define ve vector
#define chmin(x,y) x = min(x,y)

int main(){
    ll n;
    cin >> n;
    if(n==0){
        cout << 0 << endl;
        return 0;
    }
    ve<int> s;
    while(n != 0){
        if(n<0){
            s.push_back((-n)%2);
            n += n%2;
        }
        else s.push_back(n%2);
        n /= -2;
    }
    rep(i,s.size())cout << s[s.size()-1-i];
    cout<<endl;
    return 0;
}
