#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
int main(){
    cout << fixed << setprecision(10);
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    ll suma = 0,sumb = 0;
    rep(i,n) {
        suma += a[i];
        sumb += b[i];
    }
    if(suma < sumb){
        cout << -1 << endl;
        return 0;
    }else{
        ll cnt = 0, under = 0;
        vector<ll> v;
        rep(i,n){
            if(a[i] < b[i]){
                cnt++;
                under += b[i] - a[i];
            }
            else{
                v.push_back(a[i] - b[i]);
            }
        }
        sort(v.rbegin(), v.rend());
        ll sum = 0;
        int itr = 0;
        while(sum < under){
            sum += v[itr];
            itr++;
        }
        cout << itr + cnt << endl;
    }
    return 0;
}