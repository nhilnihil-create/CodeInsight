#include <bits/stdc++.h>
#include <string>
#include <vector>
#define rep(i,n) for (int i = 0;i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main(){
    int n,m;cin >> n >> m;
    ll total = 0;
    vector<int> a(n);
    vector<P> p(m);
    rep(i,n){
        cin >> a[i];
        total += a[i];
    }
    //cout << "total "<<total <<endl;
    rep(i,m){
        int b,c;
        cin >> b >> c;
        p[i] = make_pair(c,b);
    }
    sort(a.begin(),a.end());
    //for(auto v:a) cout << v << endl;
    sort(p.rbegin(),p.rend());
    //for(auto v:p) cout << v.first << endl;
    vector<int> d;
    for(auto v:p){
        rep(i,v.second) d.push_back(v.first);
        if(d.size() > n) break;
    }

    //for(auto v:d) cout <<v<< endl;

    rep(i,n){
        //cout << a[i] << " " << d[i] << endl;
        if(a[i] > d[i]) break;
        total += (d[i] - a[i]);
        a[i] = d[i];
    
    }

    cout << total << endl;



}