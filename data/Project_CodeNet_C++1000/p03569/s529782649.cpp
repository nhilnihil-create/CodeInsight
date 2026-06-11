#include "bits/stdc++.h"
#define rep(i,b) for(ll i=0;i<b;i++)
#define ll long long
using namespace std;
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define vvvl vector<vector<vector<ll>>>
#define debug(x) cerr<<#x<<" "<<x<<'\n';
bool cmp(pair<ll,ll> a, pair<ll,ll> b) { return a.second > b.second; }

ll solve(string S) {
    ll res = 0;
    for (int i = 0, j = S.size() - 1; i < j; ) {
        if (S[i] == S[j]) ++i, --j;
        else if (S[i] == 'x') ++res, ++i;
        else if (S[j] == 'x') ++res, --j;
        else return -1;
    }
    return res;
}

int main() {
    string S;
    while (cin >> S) cout << solve(S) << endl;
}