#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define REP(i,n) for (ll i = 0; i < (n); ++i)
#define RREP(i, n) for (ll i = (n) - 1; i >= 0; --i)
#define ALL(v) (v).begin(), (v).end()

const string M = "Male", F = "Female", V = "Vacant";

string ask(ll i){
    cout << i << endl << flush;
    string res;
    cin >> res;
    return res;
}

int main(){
    ll n;
    cin >> n;

    string res = ask(0);
    if(res == V){ return 0; }
    ll l = 1, r = n - 1;
    ll lpred;
    if(res == M){
        lpred = 1;
    }else{
        lpred = 0;
    }

    while(1){
        ll toask = (l + r) / 2;
        string res = ask(toask);
        if(res == V){ return 0; }
        ll resi = (res == M ? 0 : 1);
        ll predi = ((l % 2) == (toask % 2) ? lpred : 1 - lpred);
        if(resi == predi){
            l = toask + 1;
            lpred = 1 - resi;
        }else{
            r = toask - 1;
        }
    }
    return 0;
}
