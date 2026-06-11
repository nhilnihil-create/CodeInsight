#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using V = vector<ll>;
#define _GLIBCXX_DEBUG
#define rep(i, a) for(int i = 0; i < a; i++)
#define ALL(v) v.begin(), v.end()

int main(){
    int a,b,c,d; cin>>a>>b>>c>>d;
    if(abs(a-c)<=d) cout<<"Yes"<<endl;
    else if(abs(b-a)<=d&&abs(c-b)<=d)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}