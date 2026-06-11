#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod =(1e9)+7;
using P = pair<ll,ll>;

int main(){
    ll n;cin >>n;
    vector<P>p;
    for (int i = 1; i < n+1; ++i) {
        for (int j = i+1; j < n + 1; ++j) {
            if(i+j==n/2*2+1)continue;
            p.push_back(P(i,j));
        }
    }
    cout <<p.size()<<endl;
    for(auto u:p){
        cout <<u.first<< " "<<u.second<<endl;
    }
    return 0;
}