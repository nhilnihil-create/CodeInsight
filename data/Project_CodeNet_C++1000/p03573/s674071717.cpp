#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using V = vector<ll>;
#define _GLIBCXX_DEBUG
#define rep(i, a, b) for(int i = a; i < b; i++)
#define ALL(v) v.begin(), v.end()

int main(){
    int a,b,c; cin>>a>>b>>c;
    if(a==b) cout<<c<<endl;
    if(b==c) cout<<a<<endl;
    if(c==a) cout<<b<<endl;
}
