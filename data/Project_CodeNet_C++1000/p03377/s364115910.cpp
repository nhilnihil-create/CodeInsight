#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using V = vector<ll>;
#define _GLIBCXX_DEBUG
#define rep(i, a) for(int i = 0; i < a; i++)
#define ALL(v) v.begin(), v.end()

int main(){
    int a,b,x; cin>>a>>b>>x;
    if(a>x||a+b<x)cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
}