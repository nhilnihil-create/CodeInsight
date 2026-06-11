#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i < (n);i++)
using namespace std;
using ll = long long;
using pii = pair<int,int>;

int main(){
    ll n;
    cin >> n;
    vector<ll> cnt(26);
    rep(i,n){
        string s;
        cin >> s;
        cnt[s[0]]++;
    }
    ll sum = 0;
    sum += cnt['M']*cnt['A']*cnt['R'];
    sum += cnt['M']*cnt['A']*cnt['C'];
    sum += cnt['M']*cnt['A']*cnt['H'];
    sum += cnt['M']*cnt['R']*cnt['C'];
    sum += cnt['M']*cnt['R']*cnt['H'];
    sum += cnt['M']*cnt['C']*cnt['H'];
    sum += cnt['A']*cnt['R']*cnt['C'];
    sum += cnt['A']*cnt['R']*cnt['H'];
    sum += cnt['A']*cnt['C']*cnt['H'];
    sum += cnt['R']*cnt['C']*cnt['H'];
    cout << sum << endl;
}