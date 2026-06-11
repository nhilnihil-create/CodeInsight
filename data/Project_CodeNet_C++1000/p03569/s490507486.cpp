#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
long long mo = 1e9 + 7;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
template<class T, class S> void cmin(T &a, const S &b) { if (a > b)a = b; }
template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }

int main(){
    ll N;
    string s;
    cin >> s;
    N = s.size();
    vector<char> v;
    rep(i,N){
        if(s[i] != 'x'){
            v.push_back(s[i]);
        }
    }
    rep(i,v.size()/2){
        if(v[i] != v[int(v.size()) - 1 - i]){
            cout << -1 << endl;
            return 0;
        }
    }
    ll cnt = 0;
    ll l = 0;
    ll r = N-1;
    while(l < r){
        if(s[l] != s[r]){
            cnt++;
            if(s[l] == 'x'){
                l++;
            }else{
                r--;
            }
        }else{
            l++;
            r--;
        }
    }
    cout << cnt << endl;
}
