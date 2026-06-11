#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define REP(i,n) for (ll i = 0; i < (n); ++i)
#define RREP(i, n) for (ll i = (n) - 1; i >= 0; --i)
#define ALL(v) (v).begin(), (v).end()

const string YES = "Yes";
const string NO = "No";

int main(){
    ll n;
    cin >> n;

    vector<ll> a(n), b(n);
    REP(i, n){
        cin >> a.at(i);
    }
    REP(i, n){
        cin >> b.at(i);
    }

    ll ma = 0, mb = 0;
    REP(i, n){
        if(a.at(i) < b.at(i)){
            ma += (b.at(i) - a.at(i) + 1) / 2;
            mb += (b.at(i) - a.at(i)) % 2;
        }else if(b.at(i) < a.at(i)){
            mb += a.at(i) - b.at(i);
        }
    }

    if(mb > ma){
        cout << NO << endl;
    }else{
        cout << YES << endl;
    }
    return 0;
}
