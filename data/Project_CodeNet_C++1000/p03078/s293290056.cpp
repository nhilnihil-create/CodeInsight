#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define _GLIBCXX_DEBUG

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vd = vector<double>;
using vvi = vector<vi>;
using vvll = vector<vll>;
using vvd = vector<vd>;
using vvvi = vector<vvi>;
using vvvll = vector<vvll>;
using vvvd = vector<vvd>;

const double pi=3.141592653589793;
const ll MOD=1e9+7;

int main() {
    int x,y,z,k;
    cin>>x>>y>>z>>k;
    ll a[x],b[y],c[z];
    rep(i,x){
        cin>>a[i];
    }
    rep(i,y){
        cin>>b[i];
    }
    rep(i,z){
        cin>>c[i];
    }
    priority_queue<ll> q1;
    rep(i,x){
        rep(j,y){
            q1.push(a[i]+b[j]);
        }
    }
    priority_queue<ll> q2;
    for (int i=0;i<min(3000,x*y);i++){
        auto s=q1.top();
        q1.pop();
        for (int j=0;j<z;j++){
            q2.push(c[j]+s);
        }
    }
    rep(i,k){
        auto s=q2.top();
        q2.pop();
        cout<<s<<endl;
    }



    return 0;
}