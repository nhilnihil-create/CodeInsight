#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using V = vector<ll>;
#define _GLIBCXX_DEBUG
#define rep(i, a) for(int i = 0; i < a; i++)
#define ALL(v) v.begin(), v.end()

int main(){
    int a,b; cin>>a>>b;
    cout<<max(a+b,max(a-b,a*b))<<endl;
}