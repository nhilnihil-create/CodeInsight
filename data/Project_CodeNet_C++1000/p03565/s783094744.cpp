#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>
#include <cmath>
#include <tuple>
#include <queue>
#include <bitset>
#include <set>
#include <map>
#include <list>

using ll = long long;
using ld = long double;
using namespace std;
const int INF = 1e9+100;
const ll INF64 = 7e18l;
const int mod = 1000000007;
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define ALL(a) (a).begin(), (a).end()
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);


int main(){
    FIN;
    string s,t;
    cin >> s >> t;
    bool ok = true;
    bool flag = false;

    for(ll i=s.size()-t.size();i>=0;i--){
        ok = true;
        for(ll j=0;j<t.size();j++){
            if(s[i+j] == '?') continue;
            if(s[i+j] == t[j]) continue;
            ok = false;
        }

        if(ok){
            for(ll j=0;j<t.size();j++) s[i+j] = t[j];
            flag = true;
            break;
        }
    }

    if(!flag){
        cout << "UNRESTORABLE" << endl;
        return 0;
    }

    for(ll i=0;i<s.size();i++){
        if(s[i] == '?') s[i] = 'a';
    }

    cout << s << endl;
    return 0;
}
