#include <bits/stdc++.h>
using namespace std;
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <math.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using pint = pair<int,int>;
using ll=long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;

int main() {
    int n,m;cin>>n>>m;
    priority_queue<pint> q;
    rep(i,n) {int a; cin>>a; q.push(make_pair(a, 1));}
    rep(i,m) {
        int b,c; cin>>b>>c;
        q.push(make_pair(c,b));
    }

    ll ans=0;
    rep(i,n){
        auto p=q.top();
        ans+=p.first;
        q.pop();
        if(p.second>1){
            p.second--;
            q.push(p);
        }
    }

    cout<<ans<<endl;
}