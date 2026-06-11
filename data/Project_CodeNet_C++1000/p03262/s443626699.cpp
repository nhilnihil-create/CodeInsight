#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b){
    if(b==0) return a;
    else return gcd(b, a%b);
}
int main(){
    ll n, x; cin >> n >> x;
    vector<ll> p;
    for(int i=0; i<n; i++){
        ll tmp=0;
        cin >> tmp;
        p.push_back(tmp);
    }
    p.push_back(x);
    sort(p.begin(), p.end());
    ll p_size = n + 1;
    vector<ll> dis;
    for(int i=0; i<p_size-1; i++){
        dis.push_back(p[i+1]-p[i]);
    }
    sort(dis.begin(), dis.end());

    ll el = gcd(dis[0], dis[1]);
    for(int i=2; i<p_size-1; i++){
        el = gcd(el, dis[i]);
    }
    cout << el << endl;
    return 0;
}