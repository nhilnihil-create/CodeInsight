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
    int m,k;cin>>m>>k;
    if (pow(2,m)-1<k){
        cout<<-1<<endl;
        return 0;
    }
    if (k==0){
        rep(i,0,pow(2,m)){
            cout<<i<<endl;
            cout<<i<<endl;
        }
        return 0;
    }
    ll num = 0;
    rep(i,0,pow(2,m)){
        num ^= i;
    }
    if (num==0){
        cout<<k<<endl;
        rep(i,0,pow(2,m)){
            if (i==k) continue;
            cout<<i<<endl;
        }
        cout<<k<<endl;
        for(int i=pow(2,m)-1;i>=0;i--){
            if (i==k) continue;
            cout<<i<<endl;
        }
    }else{
        cout<<-1<<endl;
    }
}