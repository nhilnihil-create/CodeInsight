#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define INF 100000000
#define rep(i,s,n) for (int i = (int)(s); i < (int)(n); i++)
#define mp make_pair
ll mod = 10e9+7;
ll mod2 = 998244353;

int main(){
    int a,b;cin>>a>>b;
    if(a>=13){
        cout<<b<<endl;
    }else if(a>=6){
        cout<<b/2<<endl;
    }else{
        cout<<0<<endl;
    }
}