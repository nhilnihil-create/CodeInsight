#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define REP(i,n) for (ll i = 0; i < (n); ++i)
#define RREP(i, n) for (ll i = (n) - 1; i >= 0; --i)
#define ALL(v) (v).begin(), (v).end()


int main(){
    string s;
    cin >> s;
    ll w;
    cin >> w;
    for(ll i = 0; i < s.size(); i += w){
        cout << s.at(i);
    }
    cout << endl;
    return 0;
}
