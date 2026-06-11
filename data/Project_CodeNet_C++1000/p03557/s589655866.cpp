#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
typedef pair<int,int> P;
struct edge{int to, id;};
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define mod 1000000007

int main(){
    int n;
    cin >> n;
    vector<ll>a,b,c;
    rep(i,n){
        ll temp;
        cin >> temp;
        a.push_back(temp);
    }
    rep(i,n){
        ll temp;
        cin >> temp;
        b.push_back(temp);
    }
    rep(i,n){
        ll temp;
        cin >> temp;
        c.push_back(temp);
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    sort(c.begin(),c.end());
    ll ans = 0;
    ll indexa = 0;
    ll indexc = 0;
    //int a_b[n];
    rep(i,n){
        ll mid = b[i];
        auto itera = lower_bound(a.begin(),a.end(),mid);
        indexa = itera - a.begin();
        ll counta = indexa;
        auto iterc = lower_bound(c.begin(),c.end(),mid+1);
        ll countc = c.end() - iterc;
        ans += counta * countc;
    }
    cout << ans << endl;
}