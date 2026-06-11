#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,x) for(int i=0;i<x;i++)
#define put(ans)    cout << ans << endl;

double kaijyo(int n){
    int k(1);
    for(int i=n;i>0;i--){
        k *= i;
    }

    return k;
}

double distance(int x[],int y[],int i,int j){
    int dx = (x[i] - x[j]) * (x[i] - x[j]);
    int dy = (y[i] - y[j]) * (y[i] - y[j]);
    return sqrt(dx+dy);
}

int main(){
    int n,m;   
    cin >> n >> m;
    vector<pair<ll,ll>> v(n);
    rep(i,n){
        ll a,b;
        cin >> a  >> b;
        v[i] = make_pair(a,b);
    }

    sort(v.begin(),v.end());

    ll ans(0);
    rep(i,n){
        if(v[i].second>=m){
            ans += m*v[i].first;
            break;
        }else{
            m -= v[i].second;
            ans += v[i].first*v[i].second;
        }
    }

    cout << ans << endl;

    return 0;
}