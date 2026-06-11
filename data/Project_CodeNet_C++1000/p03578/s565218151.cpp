#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;

int main(){
    int n;
    cin>>n;
    map<int,int>d,t;
    rep(i,n){
        int a; cin>>a;
        d[a]++;
    }
    int m;
    cin>>m;
    rep(i,m){
        int a; cin>>a;
        t[a]++;
    }
    for(auto&p:t){
        if(p.second>d[p.first]){
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
    return 0;
}