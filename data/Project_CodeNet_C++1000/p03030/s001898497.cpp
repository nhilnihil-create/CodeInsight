#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll GetDigit(ll num){ return log10(num)+1; } //numの桁数を求める

int main()
{
    int n;
    cin >> n;
    string s;
    int p;
    vector<pair<pair<string,int>,int>> pair(n);
    rep(i, n){
        cin >> s >> p;
        pair[i] = make_pair(make_pair(s,-p), i);
    }
    sort(pair.begin(), pair.end());
    rep(i,n){
        cout << pair[i].second+1 << endl;
    }
    
    return 0;
}