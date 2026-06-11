#include<bits/stdc++.h>
using namespace std;
#define repl(i,x,n) for(long long i=(long long)(x);i<(long long)(n);i++)
#define rep(i,x,n) for(long i=long(x);i<long(n);i++)
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long x;
    map<long,long> m;
    rep(i,0,6){
        cin>>x;
        m[x]++;
    }
    vector<long> v;
    for(auto i:m)
        v.push_back(i.second);
    sort(v.begin(),v.end());
    if(v[0]!=1 || v[1]!=1 || v[2]!=2 || v[3]!=2)
        cout<<"NO";
    else
        cout<<"YES";
}