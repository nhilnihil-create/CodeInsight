#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
using ll = long long;
using P = pair<ll, ll>;
const long double PI = acos(-1.0L);
ll GCD(ll a, ll b) { return b?GCD(b, a%b):a; }
ll LCM(ll a, ll b) { return a/GCD(a, b)*b; }

string s;

int main() {
    cin >> s;
    int slen = s.length();
    vector<string> nsvec;
    string ns = "";
    s = s + "#";
    int ch = 0;
    for(int i = 0; i < slen; ) {
        if(s[i] == 'B') {
            if(s[i+1] == 'C') {
                ns.push_back('D');
                i += 2;
            }else {
                ns.push_back(s[i]);
                i++;
            }
        }else {
            ns.push_back(s[i]);
            i++;
        }
    }

    ns = ns + "#";

    int nslen = ns.size();
    nsvec.push_back("");
    for(int i = 0; i < nslen; ++i) {
        if(ns[i] == 'A') nsvec[ch].push_back('A');
        else if(ns[i] == 'D') nsvec[ch].push_back('D');
        else {
            if((int)nsvec[ch].size() != 0) {
                ch++;
                nsvec.push_back("");
            }
        }
    }

    ll cnt = 0;
    for(int i = 0; i < ch; ++i) {
        string cns = nsvec[i];
        reverse(cns.begin(), cns.end());
        int clen = cns.length();
        ll cc = 0;
        // cout << cns << endl;
        for(int j = 0; j < clen; ++j) {
            if(cns[j] == 'D') cc++;
            else cnt += cc;
        }
    }
    cout << cnt << endl;
}